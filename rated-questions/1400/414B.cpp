#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == 1){
                dp[i][j] = 1;
            } else{
                for (int x = j; x <= n; x+=j)
                {
                    dp[i][j] += dp[i-1][x];
                    dp[i][j] %=MOD;
                }                
            }            
        }                
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[k][i];
        ans %= MOD;
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}