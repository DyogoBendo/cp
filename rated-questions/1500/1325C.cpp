#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> g(n);

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;

        g[u].push_back(i);
        g[v].push_back(i);
    }

    queue<int> q;
    for (int i = 0; i < n-1; i++)
    {
        q.push(i);
    }
    
    
    vector<int> ans(n-1, -1);
    for (int i = 0; i < n; i++)
    {
        if(g[i].size() > 2){
            for (int j = 0; j < 3; j++)
            {
                ans[g[i][j]] = q.front();
                q.pop();
            }
            break;
        }
    }
    
    for (int i = 0; i < n-1; i++)
    {
        if(ans[i] == -1) ans[i] = q.front(), q.pop();
        cout << ans[i] << endl;
    }    
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}