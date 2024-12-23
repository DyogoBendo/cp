#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 1e6 + 6;
const int MOD = 1e9 + 7;
int dp[MAX_VALUE];
int main(){
    int n;
    cin >> n;
        

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if(i - j >= 0){
                dp[i] += (dp[i - j]);
                dp[i] %= MOD;
            }            
        }
        if(i <= 6) dp[i]++;
        
    }
    

    cout << dp[n] << endl;
    
}