#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXN = 5e3 + 10;
const int MAXT = 1e2 + 10;

int m[MAXN][MAXT];
ll dp[MAXT][2];
ll dp2[MAXT][2];

signed main(){
    darvem;

    memset(dp, -1, sizeof(dp));

    int n, t, l, u;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cin >> m[i][j];
        }
    }
    cin >> l >> u;

    
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp2[0][0] = -1;
    dp2[0][1] = -1;

    for (int i = 0; i < MAXT; i++) // verificamos qual a melhor resposta possível para cada tempo, -1 indica que é impossível
    {
        if(dp[i][0] == -1) continue;

        for (int j = 0; j < n; j++) // tentaremos expandir com cada elemento
        {
            if(dp2[i][0] == j && dp2[i][1] == -1) continue;
            
            ll curr = (dp2[i][0] == j) ? dp[i][1] : dp[i][0]; // se o melhor na posição até agora for usando ele, teremos que usar o segundo melhor
            for(int k = 0; k < l-1; k++){
                curr += m[j][k+i];
            }
            for (int a = l; a <= u && a+i <= t; a++) // e para todos os seus valores possíveis no intervalo
            {
                curr += m[j][a+i-1];
                if(dp[a+i][0] < curr){
                    dp[a+i][1] = dp[a+i][0];
                    dp2[a+i][1] = dp2[a+i][0];
                    
                    dp[a+i][0] = curr;
                    dp2[a+i][0] = j;
                } else if(dp[a+i][1] < curr){
                    dp[a+i][1] = curr;
                    dp2[a+i][1] = j;
                }
            }
        }
    }

    /*
    for (int i = 0; i <= t; i++)
    {
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    */
    
    
    cout << dp[t][0] << endl;

}