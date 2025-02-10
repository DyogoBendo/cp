#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX = 5e3 + 1;
int dp[2][MAX];

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> psumi(m + 1, vector<int>(MAX, 0)); // prefix sum of intelligence tests
    vector<vector<int>> psums(m + 1, vector<int>(MAX, 0)); // prefix sum of strenght tests

    int cnt = 0;    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;        

        if(x == 0) cnt++;
        else{
            if(x > 0)psumi[cnt][x] ++;
            else psums[cnt][-x]++;
        }
    }

    // vamos calcular a psum
    
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            psumi[i][j] += psumi[i][j - 1];
            psums[i][j] += psums[i][j - 1];
        }
        
    }

    int ans = 0;    

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int prev= dp[0][j];
            if(j > 0) prev = max(prev, dp[0][j-1]);
            dp[1][j] = prev + psumi[i][j] + psums[i][i - j];
            ans = max(ans, dp[1][j]);
        }
        for (int j = 0; j <= i; j++)
        {
            dp[0][j] = dp[1][j];
        }
        

    }    
    
    
    cout << ans << endl;
    
}

signed main(){
    solve();
}