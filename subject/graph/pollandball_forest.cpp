#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e4 + 1;
vector<vector<int>> graph;
int visited[MAX_SIZE];

void dfs(int curr){
    if(visited[curr]) return;
    visited[curr] = 1;

    for (auto v : graph[curr])
    {
        dfs(v);
    }    
}


int main(){
    int n;
    cin >> n;

    graph.resize(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        a--;
        graph[i].push_back(a);
        graph[a].push_back(i);
    }   


    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            dfs(i);
            curr ++;
        } 
    }
    
    cout << curr << endl;
    
}