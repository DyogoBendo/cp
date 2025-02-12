#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int MAXM = 2e5 + 10; 

int dp[MAXM][10];

void calc(){
    for (int i = 0; i < MAXM; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int x = 10 - j;

            if(i >= x){
                dp[i][j] = (dp[i - x][1] + dp[i - x][0]) % MOD;
            } else{
                dp[i][j] = 1;
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    int ans = 0;

    while(n){
        int x = n % 10;
        ans += dp[m][x];
        ans %= MOD;

        n /= 10;
    }
    
    cout << ans << endl;
}

signed main(){
    int t;
    calc();
    cin >> t;

    while(t--) solve();
}