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

    for (int i = 0; i <= x; i++)
    {        
        for (int j = 0; j < n; j++)
        {
            int p = i - c[j];
            if(p >= 0) dp[i] += dp[p];         
            dp[i] %= MOD;   
        }
        
    }
    
    
    cout << dp[x] << endl;
}