#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &graph, int start, int n, int end, vector<int> &painted, int color){
    queue<int> q;
    vector<int> previous(n);
    vector<int> visited(n);
    int current;
    visited[start] = 1;
    previous[start] = -1;
    q.push(start);

    while(!q.empty()){
        current = q.front();
        q.pop();
        if(current == end){
            break;
        }
        for (int e : graph[current])
        {
            if(!visited[e]){
                visited[e] = 1;
                q.push(e);
                previous[e] = current;                
            }
        }        
    }

    while(current != - 1){
        painted[current] = color;
        current = previous[current];
    }
    
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a --;
        b --;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> painted(n);
    for (size_t i = 0; i < m; i++)
    {
        int start, end, color;
        cin >> start >> end >> color;
        start --;
        end --;
        bfs(graph, start, n, end, painted, color);
    }
    
    for (int p : painted)
    {
        cout << p << " ";
    }
    cout << endl;
    
    
}