#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n+1);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    vector<int> visited(n+1);
    int cnt = 0;
    ll ans = 0;
    while(!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        if(visited[u]) continue;
        cnt++;
        visited[u] = 1;
        w = -w;
        ans += w;

        for (auto [v, c] : g[u])
        {
            pq.push({-c, v});
        }        
    }
    if(cnt != n) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}