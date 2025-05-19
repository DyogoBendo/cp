#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

const int MAX = 1e3 + 10;
const ll MOD = 1e9+7;


ll dp[MAX][MAX]; // dp[n][k]

void init(){    

    ll psum[MAX][MAX];
    for (int i = 1; i < MAX; i++)
    {        
        for (int j = 1; j < MAX; j++)
        {
            dp[i][j] = (1 + psum[i-1][j-1]) % MOD;                        
            psum[i][j] = psum[i-1][j] + dp[i][j];
            psum[i][j] %= MOD;
        }                
    }        
    
}

void solve(){

    int n, k;
    cin >> n >> k;    

    cout << dp[n][k] << endl;
}

signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}