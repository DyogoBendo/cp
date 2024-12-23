#include <bits/stdc++.h>

using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
vector<vector<int>> graph;
vector<int> visited;

int dfs(int current){
    if(visited[current]) return 0;
    visited[current] = 1;
    int c = 1;
    for (auto v: graph[current])
    {
        c += dfs(v);
    }
    return c;
    
}

signed main(){
    setIO("moocast");
    int n;
    cin >> n;
    vector<pair<int, int>> position(n);
    vector<int> power(n);
    graph.resize(n);
    visited.resize(n);    

    for (int i = 0; i < n; i++)
    {
        int x, y, p;
        cin >> x >> y >> p;
        position[i] = {x, y};
        power[i] = p * p;        
    }

    for(int i = 0; i < n; i++){
        int x = position[i].first, y = position[i].second, p = power[i];         
        for (int j = 0; j < n; j++)
        {
            int dx = (position[j].first - x), dy = (position[j].second - y);
            int distance = (dx * dx) + (dy * dy);
            if (distance <= p){
                graph[i].push_back(j);
            }
        }
        
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dfs(i));
        fill(visited.begin(), visited.end(), 0);
    }
    

    cout << ans << endl;
    
}