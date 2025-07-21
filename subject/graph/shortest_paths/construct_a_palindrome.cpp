#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int INF = 1e9;

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, char>>> g(n);
    queue<tuple<int, int>> q;
    vector<vector<int>> ans(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++){
        ans[i][i] = 0;
        q.push({i, i});
    }
    for(int i = 0; i < m; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        if(a != b){
            q.push({a, b});
            q.push({b, a});
            ans[a][b] = min(ans[a][b], 1);
            ans[b][a] = min(ans[b][a], 1);
        }
    }        

    while(!q.empty()){
        auto[a, b] = q.front(); q.pop();
        
        for (auto [v, c1] : g[a])
        {
            for (auto [u, c2] : g[b])
            {
                if(c1 == c2 && ans[a][b] + 2 < ans[u][v]){
                    ans[u][v]= ans[a][b] + 2;
                    q.push({u, v});
                }
            }            
        }            
    }
    if(ans[0][n-1] == INF) ans[0][n-1] = -1;
    cout << ans[0][n-1] << endl;
}