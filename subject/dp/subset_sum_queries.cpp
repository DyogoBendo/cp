#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e3 + 10;
const int MOD = 998244353;
int dp[MAX];

int main(){
    int q, k;
    cin >> q >> k;

    dp[0] = 1;
    

    for (int i = 1; i <= q; i++)
    {
        char c;
        int v;
        cin >> c >> v;

        if(c == '+'){
            for (int j = k; j >= v; j--)
            {
                dp[j] += dp[j - v];
                dp[j] %= MOD;
            }                     
        } else{
            for (int j = v; j <= k; j++)
            {                
                dp[j] += (MOD - dp[j - v]);
                dp[j] %= MOD;
            }
        }
        cout << dp[k] << endl;
    }
    
}