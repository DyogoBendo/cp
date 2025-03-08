#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &dst, int curr, int p, int d){
    dst[curr] = d;
    for (auto u: g[curr])
    {
        if(u != p) dfs(g, dst, u, curr, d + 1);
    }
    
}

void solve(){
    int n, st, en;
    cin >> n >> st >> en;
    en--;

    vector<vector<int>> g(n);
    vector<int> dst(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);            
    }
    
    dfs(g, dst, en, -1, 0);

    vector<pair<int, int>> o;

    for (int i = 0; i < n; i++)
    {
        o.push_back({-dst[i], i + 1});
    }
    
    sort(o.begin(), o.end());    

    for (int i = 0; i < n; i++)
    {
        cout << o[i].second << " "; 
    }
    cout << endl;
}

signed main(){
    flash;
    int t;
    cin >> t;

    while(t--) solve();
}