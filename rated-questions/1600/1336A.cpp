#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> tree(n);

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    vector<int> dst(n);
    function<int(int, int, int)> dfs = [&](int curr, int p, int prof){        
        dst[curr] = prof;
        int cnt = 0;

        int child = 0;
        for (auto e : tree[curr])
        {
            if(e!=p){
                child += dfs(e, curr, prof+1) + 1;                
            } 
        }
        dst[curr]-=child;
        return child;
    };
    
    dfs(0, 0, 0);

    sort(dst.rbegin(), dst.rend());

    int ans= 0;
    for (int i = 0; i < k; i++)
    {
        ans += dst[i];
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}