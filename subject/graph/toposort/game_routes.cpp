#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD = 1e9+7;

vector<int> toposort(vector<vector<int>> &g, int n){
    vector<int> in(n+1);
    for(int i = 1; i <=n; i++){
        for (auto e : g[i])
        {
            in[e]++;
        }        
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 1; i <= n; i++) if(in[i] == 0) q.push(i);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        ans.push_back(curr);
        for (auto e : g[curr])
        {
            if(--in[e] == 0) q.push(e);
        }        
    }
    return ans;
}

signed main(){
    //darvem;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);

    for (int i = 0; i < m; i++)
    {        
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }    

    vector<int> order = toposort(g, n);

    vector<int> dp(n+1);    
    dp[1] = 1;
    for (auto x : order)
    {        
        for (auto e : g[x])
        {
            dp[e] = (dp[e] + dp[x]) % MOD;
        }
        
    }
    
    cout << dp.back() << endl;
}