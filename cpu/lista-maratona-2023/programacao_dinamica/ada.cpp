#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    int values[26];
    cin >> n >> m;
    for (size_t i = 0; i < 26; i++)
    {
        cin >> values[i];
    }

    string a, b;

    cin >> a >> b;

    vector<vector<int>> dp;

    for(int i = 0; i <= n; i++) dp.push_back(vector<int>(m + 1));
        
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
            int ai = a[i - 1];
            int bi = b[j - 1];
            int v = 0;
            if(ai == bi){
                v = values[ai - 'a'];                
            }            
            int skip = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i - 1][j - 1] + v, skip);  
        }        
    }
    cout << dp[n][m] << endl;
}