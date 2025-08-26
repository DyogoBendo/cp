#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long


signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    vector<vector<int>> dp(n, vector<int>(2));
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    function<void(int, int)> dfs = [&](int curr, int p){
        int no_take = 0;        
        for(auto e : tree[curr]){
            if(e == p) continue;
            dfs(e, curr);
            no_take += dp[e][0];
        }
        dp[curr][1] = no_take;
        dp[curr][0] = no_take;
        for(auto e : tree[curr]){
            if(e == p) continue;
            dp[curr][0] = max(dp[curr][0], no_take - dp[e][0] + dp[e][1] + 1);
        }
    };
    dfs(0, 0);
    cout << dp[0][0] << endl;
}