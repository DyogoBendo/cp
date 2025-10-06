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

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN][2];

signed main(){
    darvem;
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i < MAXN; i++){
        dp[i][0] = ((ll) 2*dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = ((ll) 4*dp[i-1][1] + dp[i-1][0]) % MOD;
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }

}