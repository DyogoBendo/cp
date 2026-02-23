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

const int MAXN = 1e5 + 10;
const int MAXV = 200;
const int MAXK = 4;

ll dpk[MAXK][MAXN][MAXV];

ll calc(vector<ll> costs, vector<ll> values, int m){
    int n = sz(values);
    vector<ll> dp(m+1);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = m - costs[i]; j >= 0; j--){
            dp[j + costs[i]] = max(dp[j + costs[i]], dp[j] + values[i]);
            ans = max(ans, dp[j + costs[i]]);
        }
    }
    return ans;
}

ll calc2(vector<ll> costs, vector<ll> values, int m){
    assert(m <= 400);
    int n = sz(values);
    
    for(int k = 0; k <= 3; k++) for(int i = 0; i <=n; i++) for(int j = 0; j <= m; j++) dpk[k][i][j] = -1;
    for(int i = 0; i <= n; i++) dpk[0][i][0] = 0;

    ll ans = 0;
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < n; i++){
            for(int j = m - costs[i]; j >= 0; j--){
                if(dpk[k][i][j] == -1) continue;

                dpk[k+1][i+1][j + costs[i]] = max(dpk[k+1][i+1][j + costs[i]], dpk[k][i][j] + values[i]);
                if(k+1 == 3) ans = max(ans, dpk[k+1][i+1][j + costs[i]]);
            }

            for(int j = 0; j <= m; j++) dpk[k+1][i+1][j] = max(dpk[k+1][i+1][j], dpk[k+1][i][j]);
        }
    }

    return ans;
}


void solve(){
    int n, v;
    cin >> n >> v;

    vector<pair<ll, int>> tmp_volumes(n), tmp_prices(n);
    vector<ll> volumes(n), prices(n);

    for(int i = 0; i < n; i++){
        cin >> tmp_volumes[i].first;
        tmp_volumes[i].second = i;
    } 
    for(int i = 0; i < n; i++){
        cin >> tmp_prices[i].first;
        tmp_prices[i].second = i;
    } 

    sort(tmp_volumes.begin(), tmp_volumes.end());

    for(int i = 0; i < n; i++) volumes[i] = tmp_volumes[i].first, prices[i] = tmp_prices[tmp_volumes[i].second].first;

    // regular knapsack dp
    if(v <= 400){
        cout << calc(volumes, prices, v) << endl;        
    } else{
        ll ans = 0;
        // check pick only one        
        for(int i = 0; i < n; i++){
            ans = max(ans, prices[i]);            
        }

        dbg(ans);
        
        // check pick two
        vector<ll> bst_prefix(n);
        bst_prefix[0] = prices[0];        
        int l = 0;
        for(int i = 1; i < n; i++){
            while(l > 0 and v - volumes[i] < volumes[l]) l--;
            
            if(v - volumes[i] >= volumes[l]) ans = max(ans, prices[i] + bst_prefix[l]);
            bst_prefix[i] = max(bst_prefix[i-1], prices[i]);
            l++;
        }
        
        dbg(ans);
        // check pick three
        int x = (v - 100) / 3;
        dbg(x);
        for(int i = 0; i < n; i++){
            volumes[i] -= x;
            dbg(volumes[i]);
        }
        
        ans = max(ans, calc2(volumes, prices, v - (x * 3)));
        dbg(ans);
        cout << ans << endl;
    }

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}