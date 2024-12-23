#include <bits/stdc++.h>

using namespace std;

int graph[100][100];
int visited[100];

int dfs(int current){
    if(visited[current]) return 0;
    
    visited[current] = 1;
    int c = 1;
    for (int i = 0; i < 100; i++)
    {
        if(graph[current][i]) c += dfs(i);
    }

    return c;
}

int main(){
    int p, c;
    cin >> p >> c;    
    
    do
    {
        vector<pair<int, int>> edges;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                graph[i][j] = 0;
            }
                        
        }
        
        for (int i = 0; i < c; i++)
        {
            int a, b;
            cin >> a >> b;

            edges.push_back({a, b});

            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        int found = 0;
        for (auto e : edges)
        {       
            memset(visited, 0, sizeof(visited));
            graph[e.first][e.second] = 0;     
            graph[e.second][e.first] = 0;     
            int t = dfs(0);                
            if(t < p){
                cout << "YES" << endl;
                found = 1;
                break;
            }
            graph[e.first][e.second] = 1;     
            graph[e.second][e.first] = 1;     
        }        
        if(!found) cout << "NO" << endl;
        
        cin >> p >> c;
    } while (p != 0);    
}