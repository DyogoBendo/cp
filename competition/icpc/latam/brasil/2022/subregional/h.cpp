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

const int MAX = 1e4 + 100;

int n, m;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) scc(u, u);
	}
}

signed main(){
    darvem;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        gi[v].push_back(u);
    }

    kosaraju();

    vector<int> in(n), out(n), is_comp(n);    
    for(int i = 0; i < n; i++){
        is_comp[comp[i]] = 1;
        for(auto e : g[i]){
            if(comp[i] != comp[e]) out[comp[i]]++, in[comp[e]]++;
        }
    }

    int ans = 0;
    int cnt_free = 0;
    int cnt_in = 0;
    int cnt_out = 0;
    for(int i = 0; i < n; i++){        
        if(!is_comp[i]) continue;
        if(in[i] == 0 and out[i] == 0) cnt_free++;
        else if(in[i] == 0) cnt_in++;
        else if(out[i] == 0) cnt_out++;
    }

    dbg(cnt_free, cnt_in, cnt_out);
    
    if(cnt_in == 0 and cnt_out == 0){
        if(cnt_free == 1) ans = 0;
        else ans = cnt_free;
    } else if(cnt_in == cnt_out){
        if(cnt_free){
            ans = cnt_in + (cnt_free-1) + 2;
        } else ans = cnt_in;
    } else{
        ans = max(cnt_in, cnt_out) + (cnt_free-1) + 1;
    }

    cout << ans << endl;
}