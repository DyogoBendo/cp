#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int dfs(int color, int current){
    int impossible = 0;

    if(!visited[current]){
        visited[current] = color;
        for (auto v : graph[current])
        {            
            impossible = max(dfs((color + 1) % 2, v), impossible);
        }
        
    } else{
        if(visited[current] != color ) return 1;
    }
    return impossible;
}

int main(){
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            if(dfs(0, i)){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << visited[i] + 1 << " ";
    }
    cout << endl;
    
    

}