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

const int MOD = 1e9 + 7;

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<vector<tuple<int, int, int>>> g(n);
    vector<ll> weigths(n);
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w, i});
        g[v].push_back({u, w, i});
        weigths[i] = w;
    }

    vector<ll> cnt(n);

    function<int(int, int)> dfs = [&](int curr, int p){
        ll c = 1;
        for(auto [e, w, idx] : g[curr]) if(e != p){
            ll sub_tree = dfs(e, curr);
            ll rem = n - sub_tree;            
            cnt[idx] = sub_tree * rem % MOD;
            c += sub_tree;
        }
        return c;
    };
    dfs(0, 0);

    ll ans = 0;
    for(int i = 0; i < n-1; i++) ans = (ans + (weigths[i] * cnt[i] % MOD)) % MOD;    

    while(q--){
        int idx, w;
        cin >> idx >> w;
        idx--;            
        ans = (ans - (weigths[idx] * cnt[idx])  % MOD + MOD) % MOD;        
        weigths[idx] = w;
        ans = (ans + (weigths[idx] * cnt[idx])  % MOD) % MOD;                
        cout << ans << endl;
    }

}