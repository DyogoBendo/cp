#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1000;

int values[N + 1];
int dp[N + 1][N + 1];

vector<vector<int>> graph;

int main(){
    setIO("time");

    int n, m, c;
    cin >> n >> m >> c;

    graph.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    

    dp[0][0] = 0;

    int ans = 0;
    for (int d = 0; d <= N; d++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dp[d][j] != -1){
                for (auto v : graph[j])
                {
                    dp[d + 1][v] = max(dp[d + 1][v], dp[d][j] + values[v]);
                }                
            }
        }
        ans = max(ans, dp[d][0] - c * d *d);            
        
    }
    
    cout << ans << endl;

}