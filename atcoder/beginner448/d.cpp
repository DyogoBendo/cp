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

void solve(){
    int n;
    cin >> n;

    vector<int> val(n+1);
    for(int i = 1; i <= n; i++) cin >> val[i];

    vector<vector<int>> g(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    set<int> s;
    bool active = false;

    vector<int> ans(n+1);

    function<void(int, int)> dfs = [&](int curr, int p){
        int x = val[curr];
        bool was_active = active;
        bool found = false;
        if(s.count(x)) active = true, found = true;
        
        ans[curr] = active;

        s.insert(x);
        for(auto e : g[curr]) if(e != p) dfs(e, curr);
        if(!found) s.erase(x);
        
        active = was_active;
    };

    dfs(1, 1);
    for(int i = 1; i <= n; i++) cout << (ans[i] ? "Yes" : "No") << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}