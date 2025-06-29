#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> profit(n);
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }

    vector<int> visited(n);
    int ans = 0;

    function<pair<int, int>(int, int)> dfs = [&](int curr, int p){
        int added = 0;
        int tot = profit[curr];
        for (auto e : graph[curr])
        {
            if(e == p) continue;

            auto [totAdded, totProfit]=  dfs(e, curr);

            tot += totProfit;
            added += totAdded;
        }

        if(tot > added){
            ans -= added;
            ans += tot;
            added = tot;
        }
        return make_pair(added, tot);
        
    };

    
    dfs(0, 0);

    cout << ans << endl;
    
}