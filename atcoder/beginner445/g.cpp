#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
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
	int dfs(int v, int s, int f = INF) {
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
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

// Recupera as arestas do corte s-t
set<int> get_independent_set(dinitz& g, int s, int t, vector<int> &U, vector<int> &V) {
	g.max_flow(s, t);	
	vector<int> vis(g.g.size(), 0), st = {s};
	vis[s] = 1;
	while (st.size()) {
		int u = st.back(); st.pop_back();
		for (auto e : g.g[u]) if (!vis[e.to] and e.flow < e.cap)
			vis[e.to] = 1, st.push_back(e.to);
	}
    
    set<int> iset;

    for(int u : U) if(vis[u]) iset.insert(u-1);
    for(int v : V) if(!vis[v]) iset.insert(v-1);

	return iset;
}

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int g = gcd(a, b);    

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];

    dinitz d(1 + n * n + 1);

    vector<int> U, V;

    bool use_sum = (a/g + b/g) % 2 != 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        if(grid[i][j] == '#') continue;

        int ig = i/g, jg = j/g;

        int pos = 1 + (i*n + j);
        bool is_U = use_sum ? ((ig + jg) % 2 == 0) : (ig % 2 == 0);
        if(is_U){
            d.add(0, pos, 1), U.push_back(pos), U.push_back(pos);            
        } else{
            d.add(pos, n*n+1, 1), V.push_back(pos);            
        }
    }

    vector<pair<int, int>> moves;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                int f = i ? a : b;
                int s = i ? b : a;

                if(j) f = -f;
                if(k) s = -s;
                moves.push_back({f, s});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int ig = i/g, jg = j/g;                
            bool is_U = use_sum ? ((ig + jg) % 2 == 0) : (ig % 2 == 0);
            if(!is_U) continue;
            for(auto [dx, dy] : moves){
                int x = i + dx;
                int y = j + dy;
                if(x < 0 or x >= n or y < 0 or y >= n or grid[x][y] == '#') continue;
                d.add(1 + (i*n + j), 1 + (x*n + y), INF);                
            }
        }
    }

    set<int> ind_vert = get_independent_set(d, 0, n*n+1, U, V);        

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j =0 ; j < n; j++){
            if(grid[i][j] == '#') continue;
            int x = (i * n) + j;
            
            if(ind_vert.count(x)) grid[i][j] = 'o', cnt++;            
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << grid[i][j];
        cout << endl;
    } 

    dbg(cnt);

}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}