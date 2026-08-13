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

const int MAX = 2e5;

int n;
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
    cin >> n;

    map<string, int> mp;
    for(int i = 0; i < n; i++){
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;

        s1.pop_back();
        if(!mp.count(s1)) mp[s1] = mp.size();
        if(!mp.count(s4)) mp[s4] = mp.size();

        gi[mp[s4]].push_back(mp[s1]);
        g[mp[s1]].push_back(mp[s4]);
    }

    n = mp.size();
    kosaraju();

    set<int> s;

    vector<set<int>> g2(mp.size()), gi2(mp.size());    

    set<int> num_comp;
    for(int i = 0; i < mp.size(); i++){
        num_comp.insert(comp[i]);
        for(int j : g[i]) if(comp[j] != comp[i]){
            g2[comp[i]].insert(comp[j]);
            gi2[comp[j]].insert(comp[i]);
        }
    } 

    int cand = -1;
    for(auto c : num_comp){
        if(g2[c].size() == 0) cand = c;
    }

    if(cand == -1){
        cout << "impossible" << endl;
        return 0;
    }

    vector<int> vis2(mp.size());
    int tot = 0;
    function<void(int)> dfs = [&](int curr){
        if(vis2[curr]) return;
        vis2[curr] = 1;
        tot++;
        for(auto e : gi2[curr]){
            dfs(e);
        }
    };

    dfs(cand);

    cout << (tot != num_comp.size() ? "impossible" : "possible") << endl;
}