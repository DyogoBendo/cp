#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int dst(pair<int, int> v, pair<int, int> u){
    int dx = v.first - u.first;
    int dy = v.second - u.second; 
    return  (dx * dx) + (dy * dy);
}

signed main(){
    freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);

    int h, g;
    cin >> h >> g;

    vector<pair<int, int>> hp(h + 1);
    vector<pair<int, int>> gp(g + 1);


    for (int i = 0; i < h; i++)
    {
        int x, y;
        cin >> x >> y;
        hp[i + 1] = {x, y};
    }
    for (int i = 0; i < g; i++)
    {
        int x, y;
        cin >> x >> y;
        gp[i + 1] = {x, y};
    }

    vector<vector<vector<int>>> dp(h + 1, vector<vector<int>>(g + 1, vector<int>(2, INF)));

    dp[1][0][0] = 0;

    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= g; j++)
        {
            int dst1 = INF, dst2 = INF, dst3 = INF, dst4 = INF;

            if(j > 0){
                dst1 = dst(hp[i], gp[j]) + dp[i][j - 1][0]; // estava em i e fui para j
                dst3 = dst(gp[j - 1], gp[j]) + dp[i][j - 1][1]; // estava em j e fui para j
            }
            if(i > 0){
                dst2 = dst(hp[i - 1], hp[i]) + dp[i - 1][j][0]; // estava em i e fui para i
                dst4 = dst(gp[j], hp[i]) + dp[i - 1][j][1]; // estava em j e fui para i
            }
            
            dp[i][j][0] = min({dst2, dst4, dp[i][j][0]});
            dp[i][j][1] = min({dst1, dst3, dp[i][j][1]});
        }
        
    }


    cout << dp[h][g][0] << endl;
}