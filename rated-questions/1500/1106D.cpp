#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> visited(n, 0);
    pq.push(0);

    while(!pq.empty()){
        int curr=  pq.top(); pq.pop();
        if(visited[curr]) continue;

        cout << curr+1 << " ";
        visited[curr] = 1;

        for (auto e : g[curr])
        {
            if(!visited[e]) pq.push(e);
        }        
    }    
    cout <<endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}