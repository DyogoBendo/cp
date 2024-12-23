#include <bits/stdc++.h>

using namespace std;

struct MaxChildren{
    long long value = 0;
    int vertex = 0;
};

void dfs(vector<vector<int>> &graph, vector<vector<int>> &values_at_depth, vector<long long>&depth, vector<int> &parent, int current, int d = 0, int p = -1){
    values_at_depth[d].push_back(current);
    depth[current] = d;
    parent[current] = p;

    for (auto e : graph[current])
    {
        if(e != p){
            dfs(graph, values_at_depth, depth, parent, e, d + 1, current);
        }
    }    
}


void solve(){
    long long n, k, c;
    cin >> n >> k >> c;

    vector<long long> depth(n + 1);
    vector<vector<int>> values_at_depth(n + 1);
    vector<vector<int>> graph(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(graph, values_at_depth, depth, parent, 1);

    vector<pair<MaxChildren, MaxChildren>> down(n + 1);

    for (int i = n; i >= 0; i--)
    {
        for (auto v : values_at_depth[i])
        {            
            for (auto u : graph[v])
            {
                if(u == parent[v]) continue;

                if(down[u].first.value + 1 > down[v].first.value){
                    down[v].first.value = down[u].first.value + 1;
                    down[v].first.vertex = u;
                }
            }

            for (auto u : graph[v])
            {
                if(u == parent[v] || u == down[v].first.vertex) continue;

                if(down[u].first.value + 1 > down[v].second.value){
                    down[v].second.value = down[u].first.value + 1;
                    down[v].second.vertex = u;
                }
            }
               
        }        
    }

    vector<long long> up(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int v : values_at_depth[i])
        {
            int p = parent[v];
            up[v] = up[p] + 1;

            if(down[p].first.vertex == v){
                up[v] = max(up[v], down[p].second.value + 1);
            } else{
                up[v] = max(up[v], down[p].first.value + 1);
            }
        }
    }
    
    long long r = 0;

    for (int i = 1; i <= n; i++)
    {
        r = max(r, (k * max(up[i], down[i].first.value)) - (c * depth[i]));
    }

    cout << r << endl;
  
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}