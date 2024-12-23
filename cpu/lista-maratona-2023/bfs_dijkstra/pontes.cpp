#include <bits/stdc++.h>

using namespace std;

int dijskra(vector<vector<pair<int, int>>> &graph, int n){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited (n + 2);
    vector<int> distance (n + 2);
    for(int i = 0; i < n + 2; i ++) distance[i] = (numeric_limits<int>::max());    
    distance[0] = 0;
    pq.push(make_pair(0, 0));

    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        int currentW = current.first;
        int currentI = current.second;
        if(visited[currentI]) continue;
        visited[currentI] = 1;
        for(auto e : graph[currentI]){
            if(!visited[e.first]){
                if(distance[e.first] > currentW + e.second){
                    distance[e.first] = currentW + e.second;
                    pq.push(make_pair(currentW + e.second, e.first));
                }
            }
        }
    }
    return distance[n + 1];
}

int main(){
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 2);

    for (size_t i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));                
    }

    int r = dijskra(graph, n);

    cout << r << endl;
}