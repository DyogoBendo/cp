#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("fcolor");

    int n, m;
    cin >> n >> m;
        
    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
    }        

    vector<int> v(n), sz(n);
    queue<int> q;
    for(int i = 0; i < n; i++){
        sz[i] = g[i].size();    
        if(g[i].size() > 1) q.push(i);
    } 

    iota(v.begin(), v.end(), 0);
    function<int(int)> find = [&](int x){
        if(x != v[x]) return v[x] = find(v[x]);
        return x;
    };

    function<void(int, int)> un = [&](int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];        
        sz[y] = 0;       
        while(g[y].size()){
            g[x].push_back(g[y].back());
            g[y].pop_back();
        }         
        v[y] = x;
    };   
    

    while(!q.empty()){
        int k = find(q.front());
        int sz = g[k].size();            
        q.pop();

        if(sz <= 1) continue;        
        
        while(g[k].size() > 1){                                          
            int a = g[k].back(); 
            g[k].pop_back();                    
            un(g[k].back(), a);                                                    
        }
    
        q.push(g[k].back());          
    }

    int cnt = 0;
    map<int, int> mp;    
    for(int i = 0; i < n; i++){
        if(mp[find(i)] == 0){
            mp[find(i)] = (++cnt);
        }                    
        cout << mp[find(i)] << endl;    
    }
    
    
}