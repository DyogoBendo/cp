#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

vector<int> topsort(vector<vector<int>> &g, int n){
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
    darvem;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> topo = topsort(g, n);

    vector<int> dp(n+1, -1);
    vector<int> prox(n+1);
    for(int i = n-1; i >= 0; i--){
        int curr = topo[i];        
        if(curr == n) dp[curr] = 1, prox[curr] = -1;
        else{
            int add = -1;
            for (auto e : g[curr])
            {                
                if(dp[e] != -1){
                    if(dp[e] + 1 > dp[curr]) add = e, dp[curr] = dp[e]+1;                    
                } 
            }
            prox[curr] = add;
        }        
    }
    if(dp[1] == -1) cout << "IMPOSSIBLE" << endl;
    else{
        cout << dp[1] << endl;
        int curr = 1;
        while(curr != -1){
            cout << curr << " ";
            curr = prox[curr];
        }
        cout << endl;
    }
}