#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<tuple<int, int, int>> q;
    q.push({1, 1, -1});

    vector<int> visited(n+1, -1);
    vector<int> prev(n+1, -1);

    while(!q.empty()){
        auto [curr, w, p] = q.front(); q.pop();

        if(visited[curr] != -1) continue;

        visited[curr] = w;
        prev[curr] = p;

        for (auto e : g[curr])
        {
            if(visited[e] == -1) q.push({e, w+1, curr});
        }        
    }

    if(visited[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } 
    cout << visited[n] << endl;

    int curr = n;
    vector<int> ans;
    while(curr != -1){
        ans.push_back(curr);
        curr = prev[curr];
    }
    reverse(ans.begin(), ans.end());
    for(int a : ans) cout << a << " ";
    cout << endl;

}