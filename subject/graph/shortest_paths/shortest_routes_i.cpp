#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int n,m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--;b--;
        g[a].push_back({b, w});        
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    vector<int> dst(n, -1);
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if(dst[v] != -1) continue;
        
        dst[v] = d;

        for (auto [u, w] : g[v]) if(dst[u] == -1) pq.push({w+d, u});
    }

    for(int i = 0; i <n; i++) cout << dst[i] << " ";
    cout << endl;
}