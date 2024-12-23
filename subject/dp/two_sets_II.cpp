#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e2 + 1;
const int MOD = 1e9 + 7;
const int M = ((N * N) + N) / 4;

int dp[N][M];

signed main(){
    int n;
    cin >> n;

    int k = ((n * n) + n) / 2;
    if(k % 2){
        cout << 0 << endl;
        return 0;
    }
    k/= 2;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[i][j] = 0;
        }
        
    }
    
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if(j - i >= 0){
                dp[i][j] += dp[i - 1][j - i];
                dp[i][j] %= MOD;
            }
        }
        
    }

    cout << dp[n - 1][k] << endl;
    

}