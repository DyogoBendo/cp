#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD = 1e9+7;

int mul(int x, int y){
    return 1LL * x * y % MOD;
}

signed main(){
    darvem;

    int n;
    cin >> n;
    vector<vector<int>> g(n);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dp_get(n), dp_not_get(n);

    function<void(int, int)> dfs = [&](int cur, int p){
        
        dp_get[cur] = 1;
        dp_not_get[cur] = 1;
        for (auto e : g[cur])
        {
            if(e == p) continue;

            dfs(e, cur);
            dp_not_get[cur] =mul(dp_not_get[cur], (dp_not_get[e] + dp_get[e]) % MOD);
            dp_get[cur] = mul(dp_get[cur], dp_not_get[e]);
        }      
        
    };
    dfs(0, 0);
    cout << (dp_get[0] + dp_not_get[0]) % MOD << endl;
}