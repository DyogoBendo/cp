#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double

signed main(){
    //darvem;

    int s, t;
    cin >> s >> t;

    vector<int> v(s);

    for (int i = 0; i < s; i++)
    {
        cin >> v[i];
    }

    vector<vector<pair<int, int>>> graph(s);
    for (int i = 0; i < s; i++)
    {
        int e;
        cin >> e;

        for (int j = 0; j < e; j++)
        {
            int s2, p;
            cin >> s2 >> p;
            graph[i].push_back({s2, p});
        }
    }

    vector<vector<ld>> dp(t+1, vector<ld>(s));

    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j < s; j++)
        {
            ld ans = v[j];
            if(i > 0){
                for (auto e : graph[j])
                {
                    ans += dp[i-1][e.first] * e.second / 100.0;       
                }
            }
            dp[i][j] = ans;
        }
    }
    
    printf("%.6Lf\n", dp[t][0]);
}