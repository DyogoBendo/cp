#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;

int dfs(int curr){
    if(visited[curr]) return 0;    

    visited[curr] = 1;

    int qtd = 0;
    int days = 0;

    for (auto v : graph[curr])
    {
        if(!visited[v]){
            qtd ++;
            days ++;
            days += dfs(v);
        }

    }

    while(qtd){
        qtd /= 2;
        days ++;
    }
    
    return days;
}

int main(){
    int n;
    cin >> n;

    graph.resize(n);
    visited.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }    


    cout << dfs(0) << endl;
}