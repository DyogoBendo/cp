#include <bits/stdc++.h>

using namespace std;

int a[200000];
int n;

int modulo = 1000000007;

void solve(){
    int k, m = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(64, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            dp[i][j] = (dp[i][j] +  dp[i - 1][j]) % modulo;  // se ignorarmos
            dp[i][j & a[i]] =( dp[i][j & a[i]] +  dp[i - 1][j]) % modulo; // se pegarmos ele
        }         
        dp[i][a[i]] = (dp[i][a[i]] + 1) % modulo; // se começarmos por ele
    }
    for (int i = 0; i < 64; i++)
    {
        if(__builtin_popcount(i) == k){                
            m = (m + dp[n][i]) % modulo;
        } 
            
    }
    
    cout << m << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){                
        
        solve();        
        
       
    }
}