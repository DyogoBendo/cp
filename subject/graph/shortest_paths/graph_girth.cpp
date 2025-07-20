#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int INF = 1e8;

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = INF;
    auto solve = [&](int st){
        queue<tuple<int, int, int>> q;
        vector<int> visited(n+1, 0);

        q.push({st, 1, -1});

        int ans = INF;

        while(!q.empty()){
            auto [curr, w, prev] = q.front(); q.pop();            

            if(visited[curr]){
                ans=min(ans, w + visited[curr] - 2);
                continue;
            }
            visited[curr] = w;
            for (auto e : g[curr])
            {
                if(e != prev) q.push({e, w+1, curr});
            }
            
        }        
        return ans;

    };

    for(int i = 1; i <= n; i++) ans = min(ans, solve(i));

    if(ans== INF) ans = -1;
    cout << ans << endl;

}