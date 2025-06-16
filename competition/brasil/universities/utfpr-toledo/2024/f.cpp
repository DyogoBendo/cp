#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(11);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    priority_queue<pair<int, int>> pq;

    vector<int> visited(11, -1);

    pq.push({0, 0});

    while(!pq.empty()){
        auto top = pq.top();pq.pop();
        int element = top.second, dst = -top.first;

        if(visited[element] != -1) continue;

        visited[element] = dst + 1;
        for (auto v: graph[element])
        {
            pq.push({-(dst + 1), v});
        }
        
    }
        
    cout << visited[9 - 1] << endl;
    
}