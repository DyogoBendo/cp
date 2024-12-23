#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    vector<vector<bool>> grid(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            grid[i].push_back(x == '.');
        }
    }

    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!grid[i][j]) continue;
            if(i < n - 1 && grid[i + 1][j]){
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            } 
            if(j < n - 1 && grid[i][j + 1]){
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
        }
        
    }
    
    cout << dp[n - 1][n-1] << endl;

}