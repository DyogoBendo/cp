#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
const int INF = 1e9;

void solve(){
    int n;
    cin >> n;

    vector<string> entry(n);

    for (int i = 0; i < n; i++)
    {
        cin >> entry[i];
    }

    vector<vector<int>> ans(n, vector<int>(n, INF));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 0;
        q.push({i, i});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(entry[i][j] != '-'){
                ans[i][j] = min(ans[i][j], 1);
                q.push({i, j});
            } 
        }
    }
    
    while(!q.empty()){
        auto f = q.front();q.pop();
        int i = f.first, j = f.second;

        // tentamos conectar u -> i -> j -> v
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if(entry[u][i] != '-' && entry[u][i] == entry[j][v] && ans[u][v] == INF){
                    ans[u][v] = ans[i][j] + 2;
                    q.push({u, v});
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (ans[i][j] == INF ? -1 : ans[i][j]) << " ";
        }
        cout << endl;
    }
    
}

signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}