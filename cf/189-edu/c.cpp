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
    cin >> n;

    
    vector<int> dp(n+1, INF);

    string a, b;
    cin >> a >> b;
    dp[0] = 0;

    for(int i = 0; i < n; i++){        
        dp[i+1] = min(dp[i+1], dp[i] + (a[i] != b[i]));        
        if(i < n-1){
            dp[i+2] = min(dp[i+2], dp[i] + (a[i] != a[i + 1]) + (b[i] != b[i+1]));            
        }        
    }
    cout << dp.back() << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}