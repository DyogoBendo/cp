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

const int MOD =  998244353;

signed main(){
    darvem;

    string s;
    cin >> s;
    int n = sz(s);

    vector<vector<int>> dp(n+1, vector<int>(2));

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        int d = s[i-1] - '0';

        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][1];
        if(d) dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD; 

        dbg(i, dp[i][0], dp[i][1]);
    }   

    cout << dp[n][0] << endl;
}