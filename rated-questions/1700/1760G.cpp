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

void solve(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<pair<int, int>>> tree(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    bool possible=  false;
    set<int> s;
    function<void(int, int, int)> dfs = [&](int curr, int p, int tot){
        for(auto [u, w] : tree[curr]){
            if(u == p) continue;
            if(w == tot) possible= true;
            s.insert({w ^ tot});
            dfs(u, curr, w ^ tot);
        }
    };
    dfs(b, b, 0);

    function<void(int, int, int)> dfs2 = [&](int curr, int p, int tot){
        for(auto [u, w] : tree[curr]){
            if(u == p or u == b) continue;            
            if(s.count(w ^ tot)) possible = true;
            dfs2(u, curr, w ^ tot);
        }
    };
    dfs2(a, a, 0);

    cout << (possible ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}