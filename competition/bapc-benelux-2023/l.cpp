#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        a--; b--;

        g[a].push_back(b);
    }
    
    int c = 0;

    vector<int> visited(n);
    vector<int> group(n);
    vector<int> sz(n);

    for (int i = 0; i < n; i++)
    {
        group[i] = i;
        sz[i] = 1;
    }
    
    function<int(int)> find = [&](int x){
        if(group[x] == x) return x;
        return group[x]= find(group[x]);
    };

    function<void(int, int)> unite = [&](int x, int y){
        if(find(x) == find(y)) return;
        if(sz[find(x)] < sz[find(y)]) swap(x, y);

        sz[find(x)] += sz[find(y)];
        sz[find(y)] = 0;

        group[find(y)] = find(x);
    };

    function<void(int)> dfs = [&](int curr){
        cout << "curr: " << curr << endl;
        if(visited[curr]) return;
        visited[curr] = 1;

        for (auto e : g[curr])
        {
            cout << "e: " << e << endl;
            if(g[e].size()) unite(curr, e);
            dfs(e);
        }        
    };
    
    for (int i = 0; i < n; i++)
    {
        dfs(i);
    }
    
    int ans=  0;
    for (int i = 0; i < n; i++)
    {
        cout << "sz: " << sz[i] << endl;
        if(sz[i] && g[i].size()) ans ++;
    }
    
    cout << ans << endl;

}