#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int MAX_N = 2e5 + 1;

int dp[MAX_N][2];
int n, c;

void dfs(vector<vector<int>> &graph, vector<int> &values, int v, int prev){
    dp[v][0] = 0;
    dp[v][1] = values[v];  

    for (auto u : graph[v])
    {
        if(u != prev){
            dfs(graph, values, u, v);
            dp[v][0] += max(dp[u][0], dp[u][1]);
            dp[v][1] += max(dp[u][0], dp[u][1] -  2 *c);
        } 
    }
    
}

void solve(){
    cin >> n >> c;

    vector<vector<int>> tree(n, vector<int>());
    vector<int> values(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(tree, values, 0, -1);

    cout << max(dp[0][0], dp[0][1]) << endl;
    
}
signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}