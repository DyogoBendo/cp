#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n, m, v;
    cin >> v >> n >> m;

    vector<vector<tuple<int, int, int>>> graph(n);
    
    
    for (int i = 0; i < m; i++)
    {
        int a, b, t, p;
        cin >> a >> b >>t >> p;
        
        a--;b--;
        graph[a].push_back({b, t, p});
        graph[b].push_back({a, t, p});
    }
    
    int x, y;
    cin >> x >> y;
    x--;y--;
    
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, x});

    vector<int> visited(n, 0);
    vector<int> cost(n, -1);
    vector<int> time(n, -1);
    
    while(!pq.empty() && !visited[y]){
        auto [t, p, a] = pq.top(); pq.pop();
        t = -t;
        p = -p;
        bool add = false;
        if(!visited[a]){
            visited[a] = 1;
            cost[a] = p;
            time[a] = t;
            add = true;
        } else{
            if(p < cost[a]){
                cost[a] = p;
                time[a] = t;
                add = true;
            }
        }

        if(add){
            for (auto [b, t2, p2] : graph[a])
            {
                if(p + p2 > v) continue;
                pq.push({-(t + t2), -(p + p2), b});
            }            
        }

    }    
    if(!visited[y]) cout << -1 << endl;
    else cout << time[y] << endl;
}

signed main(){
    flash;
    solve();
}