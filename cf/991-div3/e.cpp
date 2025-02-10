#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve(){
    string a, b, c;
    cin >> a >> b >> c;

    int an = a.size();
    int bn = b.size();

    vector<vector<int>> dp(an + 1, vector<int>(bn + 1, INF));

    dp[0][0] = 0; // para fazer a string de tamanho 0, utilizando 0 caracteres de a e de b, fazemos 0 alterações

    for (int i = 0; i <= an; i++)
    {
        for (int j = 0; j <= bn; j++)
        {
            int p = (i + j) - 1;            
            if(i > 0){                
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (a[i - 1] != c[p]));                
            } 
            if(j > 0){                
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (b[j - 1] != c[p]));                
            }                  
        }
        
    }
    cout << dp[an][bn] << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}