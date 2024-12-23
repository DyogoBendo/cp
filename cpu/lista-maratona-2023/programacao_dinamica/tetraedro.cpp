#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007 

int main(){
    int n;
    cin >> n;

    vector<vector<int>> dp;

    for (size_t i = 0; i < 4; i++) dp.push_back(vector<int> (n + 1));

    dp[0][0] = 1;

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {            
            long long result = 0;
            for (size_t k = 0; k < 4; k++)
            {
                if(k == j) continue;
                result += dp[k][i - 1];
            }
            dp[j][i] = result % MOD;
            
        }        
    }
    cout << dp[0][n] << endl;

}