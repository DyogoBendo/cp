#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int MOD = 1e9+7;

signed main(){
    darvem;
    int n;
    cin >> n;

    vector<int> dp(26);

    dp[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 25; j >= 0; j--)
        {
            if(j < 25) dp[j+1] = (dp[j+1] + dp[j]) % MOD;
            dp[j] = dp[j] * (j + 1)  % MOD;
        }        
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += dp[i];
        ans %= MOD;
    }
    
    cout << ans << endl;
}