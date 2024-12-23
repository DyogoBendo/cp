#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }

    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(m % 2 == 0){
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if(graph[i].size() % 2 == 1){            
            ans = min(ans, a[i]);
        } else{
            for (auto j : graph[i])
            {
                if(graph[j].size() % 2 == 0){                          
                    ans = min(ans, a[i] + a[j]);
                }
            }
            
        }
    }
    
    cout << ans << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}