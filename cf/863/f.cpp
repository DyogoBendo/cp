#include <bits/stdc++.h>

using namespace std;

int dfs(int current, vector<vector<int>> &graph, vector<int> &visited){  
    visited[current] = 1;
    int s = 1;  
    for (auto u : graph[current])
    {
        if(!visited[u]){            
            s += dfs(u, graph, visited);
        }
    }    
    return s;
    
}

void remove(vector<int> &v, int x){
    for (auto &e : v)
    {
        if(e == x){
            swap(e, v.back());
            v.pop_back();

            return;
        }
    }
    
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[--u].push_back(--v);
        graph[v].push_back(u);
    }
    

    int p = sqrt(n);
    if(p * p != n){
        cout << "NO" << endl;
        return;
    }    
    int k = p;

    if(m != n + k){
        cout << "NO" << endl;
        return;
    }    

    vector<int> roots;    
    int possible = 1;

    for (int i = 0; i < n; i++)
    {
        if(graph[i].size() == 4) roots.push_back(i);
        if(graph[i].size() != 2 && graph[i].size() != 4) possible = 0;
    }
    
    if(!possible || roots.size() != k) {
        cout << "NO" << endl;
        return;
    }    

    vector<int> vis(n, 0);
    if(dfs(0, graph, vis)!= n){
        cout << "NO" << endl;
        return;
    }


    for(auto r: roots){        
        for(int i = 0; i < graph[r].size();){
            int u = graph[r][i];
            if(graph[u].size() > 2){                            
                remove(graph[u], r);
                remove(graph[r], u);
            } else i++;
        }        
    }        

    vector<int> visited  (n, 0);    
    for (auto v : roots)
    {
        int kv = dfs(v, graph, visited);              
        if(kv != k) possible = 0;
    }

    if(!possible){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}