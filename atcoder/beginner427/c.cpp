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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = m;

    for(int mask = 0; mask < (1 << n); mask++){
        int curr = 0;   
        for(int i = 0; i < n; i++){
            int c1 = (mask >> i) & 1;            
            for(auto e : g[i]){
                int c2 = (mask >> e) & 1;
                if(e > i && c2 == c1) curr++;
            }
        }        
        ans = min(curr, ans);
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}