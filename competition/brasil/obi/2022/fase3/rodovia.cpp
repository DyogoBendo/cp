#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;

int visited[MAX];

int p = 1;
int edges = 0;
int dfs(int curr, vector<vector<int>> &g){
    if(visited[curr]) return 0;

    visited[curr] = p;

    int ver = 1;
    for (auto v : g[curr])
    {
        edges ++;
        ver += dfs(v, g);
    }
    
    return ver;
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    

    int i, v;
    for (i = 0; i < n; i++)
    {
        if(!visited[i]){
            v = dfs(i, graph);

            if(v * (v - 1) > edges){
                break;
            }

            p ++;
            edges = 0;

        }
    }

    if(i == n){
        cout << -1 << endl;
        return 0;
    }    

    int k;
    set<int> s;
    for (k = 0; k < n; k++)
    {
        if(visited[k] == p && (int) graph[k].size() < (v - 1)){
            for (auto e: graph[k])
            {
                s.insert(e);
            }
            
            break;
        }
    }
    
    for (int j = 0; j < n; j++)
    {
        if(j != k && visited[j] == p && s.find(j) == s.end()){
            cout << k + 1 << " " << j + 1 << endl;
            return 0;
        }
    }
    
    
}