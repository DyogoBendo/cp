#include <bits/stdc++.h>

using namespace std;

int bfs(int start, vector<vector<int>> &graph, vector<int> &distance, int n){
    queue<int> q;
    vector<int> visited(n);
    int current;    
    visited[start] = 1;
    distance[start] = 0;
    q.push(start);

    while(!q.empty()){
        current = q.front();
        q.pop();        

        for (auto e : graph[current])
        {
            if(!visited[e]){
                q.push(e);
                visited[e] = 1;
                distance[e] = distance[current] + 1;
            }
        }
        
    }    
    return current;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph (n);
    for (size_t i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> distance(n);

    int last = bfs(0, graph, distance, n);
    int maxDistanceNode = bfs(last, graph, distance, n);
    cout << distance[maxDistanceNode] << endl;
}