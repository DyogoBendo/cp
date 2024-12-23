#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    int ns = s.size(), nt = t.size();

    vector<vector<int>> dp(ns + 1, vector<int>(nt + 1, 0));

    int ans = 0;

    for (int i = 0; i < ns; i++)
    {
        for (int j = 0; j < nt; j++)
        {
            if(s[i] == t[j]){
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            } else{
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            }
            ans = max(ans, dp[i][j]);
        }
        
    }

    for (int i = 0; i <= ns; i++)
    {
        ans = max(ans, dp[i][nt]);
    }
    for (int i = 0; i <= nt; i++)
    {
        ans = max(ans, dp[ns][i]);
    }
    
    cout << ans << endl;
}