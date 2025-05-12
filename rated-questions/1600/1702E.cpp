#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    bool possible= true;
    
    map<int, int> m;
    map<int, int> cnt;
    
    int total = 0;
    vector<pair<int, int>> edges;
    
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        if(cnt[a] >= 2) possible = false;
        if(cnt[b] >= 2) possible = false;
        if(a == b)possible = false;
        
        if(possible){
            if(cnt[a] == 1){
                edges.push_back({i, m[a]});
            } else{
                m[a] = i; 
                total++;
            } 
            if(cnt[b] == 1){
                edges.push_back({i, m[b]});
            } else{
                total++;
                m[b] = i;
            } 
        }
        cnt[a]++;
        cnt[b]++;
    }
    
    if(!possible){
        cout << "NO" << endl;
        return;
    }    
    vector<vector<int>> g(total);
    for (auto e : edges)
    {        
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }

    vector<int> visited(total, -1);
    function<void(int, int)> dfs = [&](int curr, int color){             
        if(visited[curr] == -1){
            visited[curr] = color;
        } else if(visited[curr] != color){
            possible = false;
            return;
        } else{
            return;
        }

        for (auto e : g[curr])
        {
            dfs(e, (color + 1) % 2);
        }        
    };
    for (int i = 0; i < total; i++)
    {
        if(visited[i] == -1) dfs(i, 0);
    }
    
    cout << (possible ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}