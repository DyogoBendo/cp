#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX_SIZE = 1e5 + 1;
char fj[MAX_SIZE];
int dp[MAX_SIZE][25][3];
char p[] = {'H', 'S', 'P'};
int ans, n;

int main(){
    setIO("hps");
    int k;

    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {                
        cin >> fj[i];        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l < 3; l++)
            {
                if(fj[i] == p[l]) dp[i][j][l] ++;
                dp[i + 1][j + 1][0] = max(dp[i][j][l], dp[i + 1][j + 1][0]);
                dp[i + 1][j + 1][1] = max(dp[i][j][l], dp[i + 1][j + 1][1]);
                dp[i + 1][j + 1][2] = max(dp[i][j][l], dp[i + 1][j + 1][2]);
                dp[i + 1][j][l] = max(dp[i][j][l], dp[i + 1][j][l]);
            }
            
        }
        
    }
    

    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, dp[n - 1][k][i]);
    }
    
    
    cout << ans << endl;
    
}