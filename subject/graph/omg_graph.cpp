#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int INF = 2e9 + 10;
#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;        
        g[u].push_back({-w, v});
        g[v].push_back({-w, u});
    }


    vector<int> visited(n);

    priority_queue<pair<int, int>> pq;

    for (auto e : g[0])
    {
        pq.push({e});
    }

    int ans = INF;
    int mn = INF, mx = -INF;
    while(!pq.empty()){
        auto [w, v] = pq.top(); pq.pop();        
        if(visited[v]) continue;
        w = -w;
        mn = min(mn, w);
        if(visited[n-1]) ans = min(ans, mx + mn);        
        visited[v] = 1;
        mx = max(mx, w);

        for (auto e : g[v])
        {
            if(!visited[e.second])pq.push(e);
        }
    }
    ans = min(ans, mx + mn);

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}