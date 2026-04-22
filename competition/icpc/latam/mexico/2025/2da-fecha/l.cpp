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

const int MAX = 1e5 + 100;
int val[MAX];

vector<int> g[MAX];
int sz[MAX], rem[MAX];

int cnt_up[MAX], cnt_down[MAX];

int dfs_sz(int i, int l=-1) {
	sz[i] = 1;
	for (int j : g[i]) if (j != l and !rem[j]) sz[i] += dfs_sz(j, i);
	return sz[i];
}

int centroid(int i, int l, int size) {
	for (int j : g[i]) if (j != l and !rem[j] and sz[j] > size / 2)
		return centroid(j, i, size);
	return i;
}

void dfs(vector<int> &up, vector<int> &down, int u, int p, int up_sum, int up_min, int down_min, int down_sum){    
    up_sum += val[u];
    up_min = min(val[u], up_min + val[u]);
    if(up_min >= 0) up.push_back(up_sum);

    down_sum += val[u];
    down_min = min(down_sum, down_min);
    if(down_min == down_sum and down_sum <= 0) down.push_back(down_sum);

    for(auto e : g[u]) if(e != p and !rem[e]) dfs(up, down, e, u, up_sum, up_min, down_min, down_sum);
}

ll decomp(int i) {
	int c = centroid(i, i, dfs_sz(i));
	rem[c] = 1;
    ll ans = 0;

    vector<int> all_up, all_down;

    cnt_up[0] = cnt_down[0] = 1;

    for(auto e : g[c]) if(!rem[e]){
        vector<int> up, down;
        dfs(up, down, e, -1, 0, 0, 0, 0);

        for(auto d : down){
            int target = -d - val[c];
            if(target >= 0 ) ans += cnt_up[target];
        }

        for(auto u : up){
            int target = u + val[c];
            if(target >= 0) ans += cnt_down[target];
        }

        for(auto d : down) cnt_down[-d]++, all_down.push_back(-d);
        for(auto u : up) cnt_up[u]++, all_up.push_back(u);
    }

    cnt_up[0] = cnt_down[0] = 0;

    for(auto d : all_down) cnt_down[d] = 0;
    for(auto u : all_up) cnt_up[u] = 0;

	for (int j : g[c]) if (!rem[j]) ans += decomp(j);
	return ans;
}

signed main(){
    darvem;

    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i < n; i++) val[i] = s[i] == ')' ? 1 : -1;

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << decomp(0) << endl;
}