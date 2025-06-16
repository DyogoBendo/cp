#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graphA;
vector<vector<int>> graphB;
vector<int> visited;

pair<int, int> bfs(vector<vector<int>> &graph, int start){
    queue<pair<int, int>> q;
    q.push({start, 0});

    fill(visited.begin(), visited.end(), 0);

    int ma = -1, i = -1;
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        int a = f.first,d = f.second;

        if(visited[a]) continue;

        if(d > ma){
            ma = d;
            i = a;
        }
        if(d == ma){
            i = max(i, a);
        }
        visited[a] = 1;

        for (auto v : graph[a])
        {
            q.push({v, d + 1});
        }
    }
    fill(visited.begin(), visited.end(), 0);

    return {i, ma};
}

int dfs(vector<vector<int>> &graph, int curr, int d, int total, int end){
    if(visited[curr]) return 0;
    visited[curr] = 1;

    if(curr == end) return 1;

    int is_path = 0;
    for (auto v : graph[curr])
    {
        is_path = max(is_path, dfs(graph, v, d + 1, total, end));
    }

    if(is_path && total / 2 == d){
        return curr + 1;
    }
    
    return is_path;
}

int main(){
    int n, m;
    cin >> n >> m;

    graphA.resize(n);
    graphB.resize(m);
    visited.resize(max(n, m));


    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;
        graphA[a].push_back(b);
        graphA[b].push_back(a);
    }

    for (int i = 0; i < m - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;
        graphB[a].push_back(b);
        graphB[b].push_back(a);
    }
        
    int startA = bfs(graphA, 0).first;    
    auto diametroA = bfs(graphA, startA);    
    int endA = diametroA.first;    
    int distanciaA = diametroA.second;
    int middleA = dfs(graphA, startA, 0, distanciaA, endA);    


    int startB = bfs(graphB, 0).first;
    auto diametroB = bfs(graphB, startB);
    int endB = diametroB.first;
    int distanciaB = diametroB.second;
    int middleB = dfs(graphB, startB, 0, distanciaB, endB);

    cout << middleA << " " << middleB << endl;
}