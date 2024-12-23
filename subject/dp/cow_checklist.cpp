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

    vector<pair<int, int>> h(n);
    vector<pair<int, int>> g(m + 1);
    for (int i = 0; i < n; i++)
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

    dp[0][0][0] = 0;
    dp[0][0][1] = 1e18;    
    

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= m; j++)
        {   
            int d1 = 1e18;                
            if(i > 0){                
                d1 = dst(h[i], h[i - 1]) + dp[i - 1][j][0]; // anterior um holstein e atual um holstein
                d1 = min(d1, dst(h[i], g[j]) + dp[i - 1][j][1]); // estava em um guernseys e vou para um holstein
            }
            int d2 = 1e18;

            d2 = min(d2, dst(g[j], h[i]) + dp[i][j - 1][0]);
            if(j > 1){
                d2 = min(d2, dst(g[j], g[j - 1]) + dp[i][j - 1][1]);
            }   

            dp[i][j][0] = d1;
            dp[i][j][1] = d2;
        }
        
    }
    

    int ans = 1e9;

    ans = min(dp[n - 2][m][0] + dst(h[n - 1], h[n-2]), dp[n - 2][m][1] + dst(h[n - 1], g[m]));
    
    cout << ans << endl;
}