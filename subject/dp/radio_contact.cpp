#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int dst(pair<int, int> v, pair<int, int> u){
    int dx = v.first - u.first;
    int dy = v.second - u.second;
    return (dx * dx) + (dy * dy);
}

signed main(){
    freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);

    int n, m, fx, fy, bx, by;
    cin >> n >> m >> fx >> fy >> bx >> by;

    string fj_steps, bessie_steps;
    cin >> fj_steps >> bessie_steps;

    vector<pair<int, int>> fj_positions;
    fj_positions.push_back({fx, fy});

    for (int i = 0; i < n; i++)
    {
        auto a = fj_positions[i];
        int x = a.first;
        int y = a.second;

        if(fj_steps[i] == 'N') y ++;
        if(fj_steps[i] == 'S') y --;
        if(fj_steps[i] == 'E') x ++;
        if(fj_steps[i] == 'W') x --;
        
        fj_positions.push_back({x, y});
    }
    

    vector<pair<int, int>> bessie_positions;
    bessie_positions.push_back({bx, by});

    for (int i = 0; i < m; i++)
    {
        auto a = bessie_positions[i];
        int x = a.first;
        int y = a.second;

        if(bessie_steps[i] == 'N') y ++;
        if(bessie_steps[i] == 'S') y --;
        if(bessie_steps[i] == 'E') x ++;
        if(bessie_steps[i] == 'W') x --;
        
        bessie_positions.push_back({x, y});
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // a partir de uma posição, podemos ou que ambos andem, ou apenas um dos dois
            if(i < n){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dst(fj_positions[i + 1], bessie_positions[j]));
            }
            if(j < m){
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dst(fj_positions[i], bessie_positions[j + 1]));
            }
            if(i < n && j < m){
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dst(fj_positions[i + 1], bessie_positions[j + 1]));
            }
        }
        
    }

    cout << dp[n][m] << endl;
}