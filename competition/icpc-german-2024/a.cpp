#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> visited(n, 0);

    function<int(int)> dfs = [&](int curr){
        if(visited[curr]) return 0;

        visited[curr] = 1;

        int sz = 1;
        for (auto e : g[curr])
        {
            sz += dfs(e);
        }
        return sz;        
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dfs(i));
    }
    
    cout << ans << endl;
    
}