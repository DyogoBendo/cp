#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> psum(n + 1);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];        
        psum[i + 1] = psum[i] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];        
    }

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++)
    {
        graph[i].push_back({b[i] - 1, a[i]});
        if(i > 0){
            graph[i].push_back({i - 1, 0});
        }
    }
    

    vector<int> dst(n, -1);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto top = pq.top();pq.pop();

        int d = -top.first, u = top.second;

        if(dst[u] != -1) continue;

        dst[u] = d;

        for (auto e: graph[u])
        {
            pq.push({-(d + e.second), e.first});
        }
        
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(dst[i] != -1){            
            ans = max(ans, psum[i + 1] - dst[i]);
        }
    }
    
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}