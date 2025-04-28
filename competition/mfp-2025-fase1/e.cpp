#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {            
            int p1 = g[i][j] % 2;
            int p2 = (i & 1) ^ (j & 1);
            
            g[i][j] += p1== p2;
        }
        
    }
    
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}