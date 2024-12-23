#include <bits/stdc++.h>

using namespace std;

#define int long long
int n;
int biggest = 1e10;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
vector<vector<int>> graph;
vector<int> visited;
vector<pair<int, int>> position;

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

bool check(int x){
    fill(graph.begin(), graph.end(), vector<int>());
    fill(visited.begin(), visited.end(), 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dx = position[i].first - position[j].first;
            int dy = position[i].second - position[j].second;

            if((dx * dx) + (dy * dy) <= x){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }

        }
        
    }

    return dfs(0) == n;        
}

signed main(){
    setIO("moocast");
    cin >> n;        
    graph.resize(n);
    visited.resize(n);    
    position.resize(n);    
    

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        position[i] = {x, y};        
    }


    int lo = 0;
    int hi = biggest;

    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;
        if(check(mid)){
            hi = mid;
        } else{
            lo = mid + 1;
        }
    }
    

    cout << lo << endl;
    
}