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

const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> dp(64);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 64; j++){
            dp[j & v[i]] += dp[j];
            dp[j & v[i]] %= MOD;
        }
        dp[v[i]]++;
    }

    int ans = 0;
    for(int i = 0; i < 64; i++) if(__builtin_popcount(i) == k) ans = (0LL + ans + dp[i]) % MOD;
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}