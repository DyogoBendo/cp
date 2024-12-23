#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vector<vector<pair<int, int>>> graph;
int visited[5001];

int dfs(int curr, int k){    
    if(visited[curr]) return 0;
    visited[curr] = 1;

    int c = 1;
    for (auto v : graph[curr])
    {
        if(v.second >= k){
            c += dfs(v.first, k);
        }
    }
    
    return c;
}

int main(){
    setIO("mootube");

    int n, q;
    cin >> n >> q;

    graph.resize(n);
    for (int i = 0; i < n - 1; i++)
    {   
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        b--;
        cout << dfs(b, a) - 1 << endl;

        for (int j = 0; j < n; j++)
        {
            visited[j] = 0;
        }
        
    }
    
    
}