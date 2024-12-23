#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 1;

int dp1[N][N], dp2[N][N];

int main(){
    int n, k;
    cin >> n >> k;

   dp1[0][0] = 1;
   dp2[0][0] = 1;

    vector<int> coins(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }
      
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l <= j; l++)
            {
                // caso 1, uso a moeda para gerar o valor

                if(j - coins[i] >= 0){
                    dp1[j][l] = max(dp2[j - coins[i]][l], dp1[j][l]);

                    if(l - coins[i] >= 0) dp1[j][l] = max(dp2[j - coins[i]][l - coins[i]], dp1[j][l]);
                }                
            }
            
        }

        for (int j = 0; j < N; j++)
        {
            for (int l = 0; l < N; l++)
            {
                dp2[j][l] =dp1[j][l];
            }            
        }        
        
    }    

    int ans= 0;

    for (int i = 0; i <= k; i++)
    {
        ans += dp1[k][i];
    }    
    cout << ans << endl;

    for (int i = 0; i <= k; i++)
    {
        if(dp1[k][i]) cout << i << " ";
    }    

    cout << endl;
    
}