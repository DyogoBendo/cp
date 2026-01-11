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

const int MOD = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];


    vector<vector<int>> divisors(m+1);
    for(int i = 1; i <= m; i++){
        for(int j = i; j <= m; j+= i){
            divisors[j].push_back(i);
        }
    }
    vector<ll> dp(m+1);
    dp[1] = 1;
        
    for(int i = 0; i < n - 1; i++){        
        vector<ll> ndp(m+1);        

        if(v[i] == 0){
            for(int j = m; j >= 1; j--){
                for(auto d : divisors[j]) if(j + d <=m){                    
                    ndp[j + d] += dp[j];
                    ndp[j + d] %= MOD;

                }
            }
        } else{
            for(auto d : divisors[v[i]]) if(v[i] + d <= m){
                ndp[v[i] + d] += dp[v[i]];
                ndp[v[i] + d] %= MOD;
            }
        }
        dp = ndp;
    }
    ll ans = 0;
    for(int i = 0; i <= m; i++) if(v[n-1] == 0 or v[n-1] == i) ans = (ans + dp[i])  % MOD;

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}