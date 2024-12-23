#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> graph;
vector<int> visited;
vector<pair<int, int>> locations;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

tuple<int, int, int, int> dfs(int current){
    if(visited[current]) return {200000000, -1,200000000,-1};


    visited[current] = 1;
    int x = locations[current].first, y = locations[current].second;    
    int xmin = x, xmax = x, ymin = y, ymax = y;
    for (auto v : graph[current])
    {
        auto p = dfs(v);

        xmin = min(xmin, get<0>(p));
        xmax = max(xmax, get<1>(p));
        ymin = min(ymin, get<2>(p));
        ymax = max(ymax, get<3>(p));
    }

    return {xmin, xmax, ymin, ymax};    
}

signed main(){
    setIO("fenceplan");
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n);
    locations.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        locations[i] = {x, y};
    }
    

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    
    int ans = 2e16;
    for (int i = 0; i < n; i++)
    {        
        if(!visited[i]){
            auto p = dfs(i);
            auto [xmin, xmax, ymin, ymax] = p;

            ans = min(ans, (2 * (xmax - xmin)) + (2 *(ymax - ymin)));        
        }
    }

    cout << ans << endl;
}