#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> tree(n);

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;
        tree[u].push_back({v, i});
        tree[v].push_back({u, i});
    }

    int ans =0;
    function<void(int, int, int, int)> dfs = [&](int curr, int p, int d, int idx){
        ans = max(ans, d);
        for (auto u : tree[curr])
        {
            if(u.first == p) continue;
            dfs(u.first, curr, d + (u.second < idx), u.second);
        }
    };
    
    dfs(0, 0, 0, n);

    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}