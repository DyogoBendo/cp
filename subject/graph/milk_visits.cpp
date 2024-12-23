#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vector<vector<int>> graph;
vector<char> v;
vector<int> visited;

int c;

void dfs(int curr){
    if(visited[curr]) return;
    visited[curr] = c;

    for (auto a : graph[curr])
    {
        dfs(a);
    }
    
}

int main(){
    setIO("milkvisits");
    int n, m; 
    cin >> n >> m;

    graph.resize(n);
    v.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if(v[a] == v[b]){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }        
    }

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            c ++;
            dfs(i);
        }
    }
    

    for (int i = 0; i < m; i++)
    {
        int a, b;
        char k;
        cin >> a >> b >> k;
        a--;b--;        

        if(visited[a] != visited[b]) cout << 1;
        else{
            if(v[a] == k) cout << 1;
            else cout << 0;
        }
    }

    cout << endl;
}