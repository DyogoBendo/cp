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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n+1);

    for(int i = 0; i <n-1; i++){
        int u, v;
        cin >> u >> v;
        
        g[u].push_back(v);
        g[v].push_back(u);        
    }

    int cnt0 = 0, cnt1 = 0;
    vector<int> tmp(k);
    for(int i = 0; i < k; i++){
        cin >> tmp[i];        
    }     

    sort(tmp.begin(), tmp.end());

    for(int i = 0; i < k; i++){
        if(tmp[i] == tmp[0]) cnt0++;
        else cnt1++;
    }    

    vector<int> dp(n+1), dp2(n+1);    

    function<void(int, int)> dfs = [&](int curr, int p){
        vector<pair<int, int>> v;        
        for(auto e : g[curr]) if(e != p){
            dfs(e, curr);
            v.push_back({dp[e] - dp2[e], e});
        }
        
        sort(v.rbegin(), v.rend());

        int tota = 0, cnta =0;
        for(int i = 0; i < min(sz(v), cnt0) and v[i].first >= 0; i++){
            tota += dp[v[i].second];
            cnta ++;
        }
        int lft = sz(v) - cnta;        
        if(lft > cnt1){
            for(; sz(v) - cnta > cnt1 and cnta < sz(v); cnta++ ) tota += dp[v[cnta].second];
        }

        int totb = 0;
        for(int i = cnta; i < sz(v); i++) totb += dp2[v[i].second];
                
        if(cnta < cnt0){
            dp[curr] = tota + totb + 1;            
        } else{
            int idx = v[cnta-1].second;            
            dp[curr] = tota - dp[idx] + dp2[idx] + totb + 1;
        }
        dp2[curr] = tota + totb;            
    };
    dfs(1, 1);

    int l = max(dp[1], dp2[1]);
    int r = n - l;    
    ll ans = (1LL * tmp[0] * l) + (1LL * tmp.back() * r);

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}