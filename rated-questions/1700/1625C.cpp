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

#define int long long

const int INF = 1e18;

void solve(){
    int n, l, k;
    cin >> n >> l >> k;

    vector<int> d(n), a(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    d.push_back(l);

    vector<vector<int>> dp(n+1, vector<int>(k+1, INF));    

    dbg(n, k, l);
    for(int i = 0; i <= k; i++) dp[0][i] = 0;
    int ans = INF;
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(dp[i][j] == INF) continue;            
            for(int x = 0; x <= k - j and x < n - i; x++){
                dbg(i, j, x, dp[i][j], d[i+x+1], d[i], a[i]);
                dp[i+x+1][j+x] = min(dp[i+x+1][j+x], dp[i][j] + (d[i+x+1] - d[i]) * (a[i]));
            }
        }
    }
    for(int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}