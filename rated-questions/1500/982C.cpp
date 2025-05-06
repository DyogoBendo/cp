#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int ans = 0;

    if(n%2){
        cout << -1 << endl;
        return;
    }

    function<int(int, int)> dfs = [&](int curr, int p){
        int parity = 1;
        for (auto u : tree[curr])
        {
            if(u == p) continue;
            if(!dfs(u, curr)) ans ++;
            else parity ++;
        }
        parity %= 2;
        return parity;
    };
    

    dfs(0, 0);
    cout << ans << endl;
}


signed main(){
    //darvem;
    int t = 1;

    while(t--) solve();
}