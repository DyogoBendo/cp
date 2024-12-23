#include <bits/stdc++.h>

using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int T = 1e3 + 1;

int dp[T][T][2];

int dst(pair<int, int> a, pair<int, int> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

signed main(){
     setIO("checklist");

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> h(n + 1);
    vector<pair<int, int>> g(m + 1);
    for (int i = 0; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        h[i] = {x, y};
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[i] = {x, y};
    }    


    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j][0] = 1e18;    
            dp[i][j][1] = 1e18;    
        }
        
    }
    dp[1][0][0] = 0;    

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {                           
            if(i > 0){                
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dst(h[i], h[i - 1]));                
            }
            if(j > 0){
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dst(g[j],  g[j - 1]));
            }

            if(i > 0 && j > 0){
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + dst(h[i], g[j]));                                
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dst(g[j],  h[i]));
            }
        }        
    }
        
    
    cout << dp[n][m][0] << endl;
}