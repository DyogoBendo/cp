#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int INF = 1e9;
int n, m, a, b;
vector<vector<pair<int, int>>> g;

int solve(int x, int y){        
    set<pair<int, int>> current_nodes;
    for(int i = 0; i < n; i++){
        if(i == a) current_nodes.insert({0, a});
        else current_nodes.insert({INF, i});
    }
    
    vector<int> dst(n, INF);
    while(!current_nodes.empty()){
        auto [d, v] = *current_nodes.begin();
        current_nodes.erase(current_nodes.begin());        
        dst[v] = d;

        for (auto [u, w] : g[v])
        {
            if(v == x && u == y) continue;            
            if(w+d < dst[u]){
                current_nodes.erase({dst[u], u});
                dst[u] = w+d;
                current_nodes.insert({dst[u], u});
            }            
        }        
    }
    if(dst[b] == INF) return -1;
    return dst[b];
}

signed main(){
    darvem;

    cin >> n >> m >> a >> b;
    a--;b--;
    g.resize(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;        

        u--;v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    vector<int> path;
    int x;
    cin >> x;
    for(int i = 0; i < x; i++){
        int k;
        cin >> k;
        k--;
        path.push_back(k);
    } 

    for(int i = 0; i < x - 1; i++){
        cout << solve(path[i], path[i+1]) << endl;
    }        
}