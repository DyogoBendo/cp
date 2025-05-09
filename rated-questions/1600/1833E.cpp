#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<int> original(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        x--;
        original[i] = x;
        graph[i].push_back(x);
        graph[x].push_back(i);        
    }
    

    vector<int> visited(n);
    int c =0;
    function<int(int, int)> dfs = [&](int curr, int prev){
        if(visited[curr]) return 0;
        visited[curr] = c;                
        int p = curr == original[original[curr]];        
        for (auto e : graph[curr])
        {            
            p = max(dfs(e, curr), p);
        }               
        return p;        
    };    

    int mn = 1;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){                        
            c++;
            int k = dfs(i, i);                      
            if(!k) mn ++;
        }
    }
    
    cout << min(c, mn) << " " << c << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}