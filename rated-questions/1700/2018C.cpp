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
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 1e9;        
    vector<int> min_depth_remove(n), max_depth_remove(n), depth(n);
    function<int(int, int, int)> dfs = [&](int curr, int p, int d){
        int mx = d;    
        for(auto e : g[curr]) if(e != p) mx = max(mx, dfs(e, curr, d+1));                    
        dbg(curr, mx);
        max_depth_remove[mx]++;
        depth[d]++;
        
        return mx;
    };

    dfs(0, 0, 0);    

    vector<int> psum(n+1), ssum(n+1);
    for(int i = 0; i < n; i++) psum[i+1] = psum[i] + max_depth_remove[i];
    for(int i = n - 1; i >=0; i--) ssum[i] = ssum[i+1] + depth[i];

    for(int i = 0; i < n; i++){
        dbg(i, psum[i], ssum[i+1]);
        ans = min(ans, psum[i] + ssum[i + 1]);
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}