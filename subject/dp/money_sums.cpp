#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 + 1;
const int X = 1e5 + 1;

int dp[N][X] = {0};

int main(){
    int n;
    cin>> n;

    vector<int> coins(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }
    
    dp[0][0] = 1;

    int cnt = 0;
    int ma = 0;
    for (int i = 1; i <= n; i++)
    {
        int v = coins[i];
        cnt = 0;
        for (int j = X; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j];
            if(j - v >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - v]);
            cnt += dp[i][j];
            if(dp[i][j]) ma = max(ma, j);
        }
        
    }

    cout << cnt - 1 << endl;
    for (int i = 1; i <= ma; i++)
    {
        if(dp[n][i]) cout << i << " ";
    }
    cout << endl;
    
    
}