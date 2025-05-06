#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n);

    for (int i = 0; i < n-1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(!c){
            g[--a].push_back(--b);
            g[b].push_back(a);
        }
    }
    
    ll ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = (1LL) * (ans * n) % MOD;
    }

    vector<int> visited(n, 0);
    function<int(int, int)> dfs = [&](int curr, int p){
        if(visited[curr]) return 0;
        visited[curr] = 1;

        int sz = 1;
        for (auto e : g[curr])
        {
            if( e == p) continue;
            sz += dfs(e, curr);
        }
        
        return sz;
    };
    
    for (int i = 0; i < n; i++)
    {
       int sz = dfs(i, i);

       ll curr = 1;
       for (int j = 0; j < k; j++)
       {
            curr = (1LL) * curr * sz % MOD;
       }
       
       ans = (ans - curr + MOD) % MOD;
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    while(t--) solve();
}