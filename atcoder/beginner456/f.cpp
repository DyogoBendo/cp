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

const ll INF = 1e18;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<ll> dp(n+1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){        
        dp[i+1] = min(dp[i+1], dp[i] + v[i]);
        if(i and i < n-1) dp[i+2] = min(dp[i+2], dp[i] + v[i+1]);        
    }

    for(int i = 0; i <= n; i++) cout << dp[i] << " ";
    cout << endl;
    
    ll bst = dp[k];
    ll bst_remove = 0;
    for(int i = k+1; i <= n; i++){
        ll min_cost = v[i-k-1];
        if(i-k > 1) min_cost = min(v[i-k-1], v[i-k-2]);
        ll curr =dp[i - k] - min_cost;

        dbg(i, curr, dp[i], dp[i-k]);

        bst_remove = max(curr, bst_remove);

        bst = min(bst, dp[i] - bst_remove);
    }

    cout << bst << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}