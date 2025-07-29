#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        g[b].push_back(a);
    }

    vector<int> visited(n+1), dangling(n+1), ans;    
    function<bool(int)> dfs = [&](int curr){
        if(visited[curr]) return true;
        if(dangling[curr]) return false;
        dangling[curr] = 1;
        
        for (auto e : g[curr])
        {
            if(!visited[e]){
                bool result = dfs(e);
                if(result == false) return false;                
            } 
        }

        visited[curr] = 1;
        dangling[curr]=  0;
        ans.push_back(curr);        
        return true;
    };

    bool possible = true;
    for(int i = 1; i <=n; i++){
        if(!dfs(i)){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }        
    }
    for (auto a : ans) cout << a << " ";
    cout << endl;    
}