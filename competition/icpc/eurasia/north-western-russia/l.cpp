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

const int MAXN = 2000 + 17;
const int MAXK = 2000 + 13;

ld dp[MAXN][MAXK];

void init(){
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXK; j++){
            ld t = dp[i-1][j] - dp[i-1][j-1];
            t = max(t, (ld) 0.0);
            t = min((ld) 1.0, t);

            dp[i][j] = dp[i-1][j] + (1 - t) * (1 - t) * 0.5;            
        }
    }
}

void solve(){
    int n, k, d;
    cin >> n >> k >> d;    
    
    ld dx = d;
    ld nx = n;
    ld ans = (dx*nx*0.5) + 0.5 + dp[n-1][k-1];

    cout << fixed << setprecision(12) << ans << endl;
}


signed main(){
    darvem;
    init();
    int t = 1;
    cin >> t;

    while(t--) solve();
}