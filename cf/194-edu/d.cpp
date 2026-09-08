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

const int INF = 1e9;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> dp(11, INF);
    dp[5] = 0;

    for(int i = 0; i < n; i++){
        vector<int> ndp(11, INF);
        for(int j = 0; j < 11; j++){
            if(dp[j] == INF) continue;
            int x = j - 5;
            for(int k = -5; k <= 5; k++){
                if(k == 0) continue;
                if(abs(x + k) >= 5) continue;
                if(x + k < 0 and s[i] != '-') continue;
                if(x + k > 0 and s[i] != '+') continue;
                if(x + k == 0 and s[i] != '0') continue;

                int p = x + k + 5;
                ndp[p] = min(ndp[p], max(abs(k), dp[j]));
            }
        }
        dp = ndp;
    }

    int ans = INF;
    for(int i = 0; i < 11; i++) ans = min(ans, dp[i]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}