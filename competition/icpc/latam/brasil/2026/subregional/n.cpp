#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

signed main(){
    darvem;

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }

    vector<vector<int>> ans(n);

    int k = 0;
    for(auto [u, v] : edges){
        vector<int> visited(n);
        visited[v] = 1;
        k++;
        function<void(int)> dfs = [&](int curr){
            if(visited[curr]) return;            
            visited[curr] = 1;
            ans[curr].push_back(k);
            for(auto x : g[curr]) dfs(x);
        };    
        dfs(u);

        k++;
        visited[v] = 0;
        dfs(v);
    }

    cout << k << endl;
    for(auto v : ans){
        cout << sz(v);
        for(auto x : v) cout << " " << x;
        cout << endl;
    } 

}