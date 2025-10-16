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

const int MAX = 1e5+10;

// Kosaraju
//
// O(n + m)

int n, m;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice
int in[MAX];
ld prob[MAX], p[MAX];

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
    dbg(k, c);
	vis[k] = 1;
	comp[k] = c;
    prob[c] *= p[k];
	for (int i = 0; i < (int) gi[k].size(); i++){
        dbg(i, gi[k][i]);
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
        else if(comp[gi[k][i]] != c) in[c]++;
    }
}

void kosaraju() {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);

	for (int i = 1; i <= n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]){
            prob[u] = 1;
            scc(u, u);
        } 
	}
}

signed main(){
    darvem;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        p[i] = 1 - p[i];
    } 

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        dbg(a, b);
        g[b].push_back(a);
        gi[a].push_back(b);
    }

    kosaraju();

    ld ans = 0;
    for(int i = 1; i <= n; i++){
        dbg(i, in[i]);
        if(in[i] == 0) ans = max(ans, prob[i]);
    }
    cout << setprecision(200) << ans << endl;

}