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

    vector<int> charge(n);
    vector<vector<pair<int, int>>> tree(n);

    for (int i = 0; i < n; i++)
    {
        cin >> charge[i];
    }
    

    for (int i = 0; i < n-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--;v--;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }


    int ans = 0;
    function<int(int, int)> dfs = [&](int curr, int p){
        int result = charge[curr];
        for (auto [e, w] : tree[curr])
        {
            if(e == p) continue;

            int add = dfs(e, curr);
            ans += abs(add) * w;
            result += add;
        }
        
        return result;
    };

    dfs(0, 0);

    cout << ans << endl;
}