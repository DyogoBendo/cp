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

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> tree(n);    
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});           
    }

    int m;
    cin >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> parity(n);

    ll ans = 0;
    function<int(int, int)> dfs = [&](int curr, int p){        
        int x = sz(g[curr]) % 2;
        for(auto [u, w] : tree[curr]) if(u != p){
            int r = dfs(u, curr);
            if(r) ans += w;
            x ^= r;
        }
        return x;
    };

    dfs(0, 0);

    cout << ans << endl;
}