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

const int INF = 2e9 + 10;

// Dinitz
//
// O(min(m * max_flow, n^2 m))
// Grafo com capacidades 1: O(min(m sqrt(m), m * n^(2/3)))
// Todo vertice tem grau de entrada ou saida 1: O(m sqrt(n))

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

signed main(){
    darvem;

    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> cap(n, vector<int>(k));

    for(int i = 0; i < n; i++) for(int j = 0; j < k; j++) cin >> cap[i][j];

    vector<vector<vector<int>>> g(n, vector<vector<int>>(k));

    for(int i = 0; i < m; i++){
        int u, v, f;
        cin >> f >> u >> v;
        f--;
        u--; v--;
        g[f][u].push_back(v);
    }

    dinitz d(2*(n - 1)*k + k + 2);    

    int cnt_prev = 1;
    for(int i = 0; i < k; i++) d.add(0, i+1, cap[0][i]);    
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < k; j++) for(auto e : g[i][j]) d.add(cnt_prev + j, cnt_prev + k + e, INF);

        cnt_prev += k;
        for(int j = 0; j < k; j++) d.add(cnt_prev + j, cnt_prev + j + k, cap[i+1][j]);                
        cnt_prev += k;
    }
    
    vector<int> ans(n);
    int tot = cnt_prev + k;
    for(int i = n-1; i>= 0; i--){
        int pos = 2*i*k;        
        for(int j = 0; j < k; j++){            
            d.add(1 + pos + j, tot, INF);        
        } 
        ans[i] = d.max_flow(0, tot);
    }

    for(auto a : ans) cout << a << " ";
    cout << endl;

}