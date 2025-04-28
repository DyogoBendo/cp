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
    
    vector<vector<int>> visited(n, vector<int>(m, 0));
    function<void(int, int)> dfs = [&](int i, int j){
        if(visited[i][j]) return;
 
        visited[i][j] = 1;
        bool change = false;                       
        if(i > 0 && g[i-1][j] == g[i][j]){            
            change = true;            
        }        
        if(i < n -1  && g[i+1][j] == g[i][j]){            
            change = true;                        
        }        
        if(j > 0 && g[i][j-1] == g[i][j]){            
            change = true;                                    
        }        
        if(j < m-1 && g[i][j+1] == g[i][j]){            
            change = true;                                                
        }
        
        g[i][j] += change;        
 
        if(i > 0 && g[i-1][j] == g[i][j]){            
            dfs(i-1, j);
        }        
        if(i < n -1  && g[i+1][j] == g[i][j]){            
            dfs(i+1, j);
        }        
        if(j > 0 && g[i][j-1] == g[i][j]){            
            dfs(i, j-1);
        }        
        if(j < m-1 && g[i][j+1] == g[i][j]){            
            dfs(i, j+1);            
        }
    };
     
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!visited[i][j]){
                dfs(i, j);
            }
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