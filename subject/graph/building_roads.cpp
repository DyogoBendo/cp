#include <bits/stdc++.h>

using namespace std;
    
vector<int> visited;
vector<vector<int>> graph;

void dfs(int root, int current){
    if(!visited[current]){        
        visited[current] = root;
        for (auto v: graph[current])
        {            
            dfs(root, v);
        }
        
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    visited.resize(n);
    graph.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);        
    }


    vector<int> roots;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            roots.push_back(i + 1);
            dfs(i + 1, i);
        }
    }
        
    cout << roots.size() - 1 << endl;

    for (int i = 0; i < roots.size() - 1; i++)
    {
        cout << roots[i] << " " << roots[i + 1] << endl;
    }
    
    
}