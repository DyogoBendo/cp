#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_SIZE = 1e4 + 1;
int dp[MAX_SIZE];
int MOD = 1e9 + 7;

signed main(){

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;

    int n;

    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] +  (4 * dp[i - 2] % MOD) + (2 * dp[i - 3] % MOD) ) % MOD;
    }
    

    cout << dp[n] << endl;
}