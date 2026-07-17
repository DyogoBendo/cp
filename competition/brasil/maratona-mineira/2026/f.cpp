#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ld long double
#define sz(a) ((int) a.size())

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG 
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int INF = 1e9;

struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int t, int f = INF) {
		if (!f or v == t) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, t, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};


void solution(){
    int n, m;
    cin >> n >> m;

    dinitz d1(n+2), d2(n+2);

    vector<vector<int>> g(n+1);


    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);

        d1.add(u, v, 1);
        d1.add(v, u, 1);

        d2.add(u, v, 1);
        d2.add(v, u, 1);
    }

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;    

    vector<int> visited(n+1), visited2(n+1);
    function<void(int)> dfs = [&](int curr){
        if(visited[curr]) return;
        visited[curr] = 1;
        for(auto e : g[curr]) dfs(e);
    };    

    function<void(int)> dfs2 = [&](int curr){
        if(curr == a2) return;
        if(visited2[curr]) return;
        visited2[curr] = 1;
        for(auto e : g[curr]) dfs2(e);
    };    

    dfs(a1);
    dfs2(a1);

    d1.add(0, a1, INF);
    d1.add(a2, n+1, INF);

    d2.add(0, b1, INF);
    d2.add(b2, n+1, INF);

    auto d3 = d1;
    d3.add(0, b1, INF);
    d3.add(b2, n+1, INF);

    if(visited[b2] and visited[a2] and visited[b1]){
        assert(1);             
        
        if(!visited2[b1]){
            cout << d1.max_flow(0, n+1) + d2.max_flow(0, n+1) << endl;            
        } else{            
            d1.add(b2, n+1, INF);
            cout << d1.max_flow(0, n+1) << endl;
        }
        
    } else if(visited[b2] and visited[a2] and !visited[b1]){
        assert(1); 
        cout << d1.max_flow(0, n+1) << endl;
    } else if(visited[b2] and !visited[a2] and visited[b1]){
        assert(1);
        cout << d2.max_flow(0, n+1) << endl;
    } else if(!visited[b2] and visited[a2] and !visited[b1]){
        assert(1);
        cout << d1.max_flow(0, n+1) + d2.max_flow(0, n+1) << endl;
    } else if(visited[b2] and !visited[a2] and !visited[b1]){
        assert(0); // c2
        cout << 0 << endl;
    } else if(!visited[b2] and visited[a2] and visited[b1]){
        assert(0); // c3
        cout << d1.max_flow(0, n+1) << endl;
    } else if(!visited[b2] and !visited[a2] and visited[b1]){
        assert(0); // c4
        cout << 0 << endl;
    } else if(!visited[b2] and !visited[a2] and !visited[b1]){
        assert(0); // c5
        cout << d2.max_flow(0, n+1) << endl;
    } else{
        assert(0);
    }
}

signed main(){
    fastio;
    int cases = 1;
    
    //cin >> cases;
    for(int i = 0; i < cases; i++){
        solution();
    }
}