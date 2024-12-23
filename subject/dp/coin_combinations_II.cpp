#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e6;
const int MOD = 1e9 + 7;
int dp[MAX_SIZE];

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }


    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {        
        for (int j = 1; j <= x; j++)
        {
            int p = j - c[i];            
            if(p >= 0){                
                dp[j] += dp[p];
                dp[j] %= MOD;
            } 
        }
        
        
    }
    
    
    cout << dp[x] << endl;
}