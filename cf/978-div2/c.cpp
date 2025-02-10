#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5 + 10;

int dp[MAX][3];
void solve(){
    int n;
    cin >> n;


    array<vector<int>, 2> x;    

    for (int i = 0; i < 2; i++)
    {           
        string s;
        cin >> s;
        vector<int> vx(n + 1);
        for (int k = 0; k < n; k++)
        {
            vx[k + 1] = s[k] == 'A';            
        }
        x[i] = vx;                
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= n; j++)
        {                        
            dp[j][i] = -1;
        }
        
    }
    dp[0][0] = 0;    
    
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            if(dp[k][i] != -1){
                int vt = 0, val = dp[k][i];
                if(i == 0){
                    vt = (x[0][k + 1] + x[0][k + 2] + x[0][k + 3]) / 2 + (x[1][k + 1] + x[1][k+2] + x[1][k+3]) / 2; // adicionar horizontalmente
                    dp[k + 3][0] = max(dp[k + 3][0], vt + val);

                    vt = (x[0][k+1] + x[0][k + 2] + x[1][k+1]) / 2;
                    dp[k + 1][1] = max(dp[k + 1][1], val + vt);

                    vt = (x[1][k + 1] + x[1][k + 2] + x[0][k+1]) / 2;
                    dp[k + 1][2] = max(dp[k+ 1][2], val + vt);
                } else if(i ==1){
                    vt = (x[0][k + 2] + x[0][k + 3] + x[0][k + 4]) / 2 + (x[1][k + 1] + x[1][k+2] + x[1][k+3]) / 2; // adicionar horizontalmente
                    dp[k+3][1] = max(dp[k + 3][1], vt + val);

                    vt = (x[1][k + 1] + x[1][k + 2] + x[0][k+2]) / 2;
                    dp[k + 2][0] = max(dp[k + 2][0], val + vt);
                } else{
                    vt = (x[1][k + 2] + x[1][k + 3] + x[1][k + 4]) / 2 + (x[0][k + 1] + x[0][k+2] + x[0][k+3]) / 2; // adicionar horizontalmente
                    dp[k+3][2] = max(dp[k + 3][2], vt + val);

                    vt = (x[0][k + 1] + x[0][k + 2] + x[1][k+2]) / 2;
                    dp[k + 2][0] = max(dp[k + 2][0], val + vt);
                }
            }
        }
                
    }

    cout << dp[n][0] << endl;
}

int main(){
    fastio
    
    int t;
    cin >> t;
    while(t--) solve();
}