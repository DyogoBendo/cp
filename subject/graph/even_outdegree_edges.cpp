#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> graphAns;
vector<int> visited;
vector<int> quantity;

void dfs(int curr){
    if(visited[curr]) return;

    visited[curr] = 1;

    for (auto v : graph[curr])
    {
        if(quantity[v] == 0) continue;

        if(quantity[v] % 2){
            quantity[v] --;
            quantity[curr] --;
            graphAns.push_back({curr, v});
        }
    }

    if(quantity[curr] % 2)
    
}

int main(){
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n);
    quantity.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);

        quantity[a] ++;
        quantity[b] ++;
    }

    if(m % 2){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    dfs(0);
}