#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int dfs(int current){
    if(!visited[current]){
        visited[current] = 1;
        int s = 1;
        for (auto v : graph[current])
        {
            s += dfs(v);
        }
        return s;
    }
    return 0;
}

int main(){
     setIO("closing");
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }    

    int current;
    vector<int> off(n);
    for (int i = 0; i < n; i++)
    {
        int k= 0;
        while(off[k] && k < n){
            k ++;
        }

        if(dfs(k) < n - i){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
        cin >> current;
        current --;
        off[current] = 1;        
        visited = off;
    }
    
}