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
    int n;
    cin >> n;

    vector<int> v(n+1);

    for(int i = 1; i <= n; i++) cin >> v[i];

    vector<int> dp(n+1);

    dp[0] = 1;
    for(int k = 1; k <= n; k++){        
        vector<int> p(k+1);        
        p[k] = k;
        dp[k] = dp[k-1];
        for (int i = k-1, j = k; i > 0; i--) {            
            while (j != k and v[j] != v[i]){                
                j = p[j+1];            
            }             
            if (v[j] == v[i]) j--;            
            p[i] = j;            
            if(j == k) dp[k] = (dp[k] + dp[i-1]) % MOD;
        }        
    }

    cout << dp[n] << endl;
}   


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}