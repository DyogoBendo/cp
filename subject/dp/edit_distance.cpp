#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, max(n, m)));

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i < n && j < m && s1[i] == s2[j]){
                // nao fazer nada
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            } 
            // remover um caracter de s1 == inserir um caracter em s2            
            if(i < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);

            // remover um caracter de s2 == inserir um caracter em s1
            if(j < m) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

            // trocar um caracter de s1 ou s2
            if(i < n && j < m) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);            
        }        
    }

    cout << dp[n][m] << endl;
    
}