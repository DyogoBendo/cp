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
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }

    vector<int> visited(n+1), dangling(n+1), ans;    
    function<int(int)> dfs = [&](int curr){        
        if(dangling[curr]) return curr;
        dangling[curr] = 1;
        ans.push_back(curr);
        
        for (auto e : g[curr])
        {
            if(!visited[e]){
                int result = dfs(e);        
                if(result) return result;        
            } 
        }

        visited[curr] = 1;
        dangling[curr]=  0;
        ans.pop_back();        
        return 0;
    };

    for(int i = 1; i <=n; i++){
        int d = dfs(i);
        if(d){
            bool possible = false;
            vector<int> ans2;
            for(int j = 0; j < ans.size(); j++){
                if(ans[j] == d) possible = true;
                if(possible) ans2.push_back(ans[j]);
            }
            ans2.push_back(d);
            cout << ans2.size() << endl;
            for(auto a : ans2) cout << a << " ";            
            cout << endl;
            return 0;
        }        
    }
    cout << "IMPOSSIBLE" << endl;
    for (auto a : ans) cout << a << " ";
    cout << endl;    
    
}