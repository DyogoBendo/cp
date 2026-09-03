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

    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);
    for(int i = 0; i < n; i++) cin >> v[i];

    int prev = 0;
    vector<int> psum(n + 1);
    for(int i = 0; i < n; i++){
        if(v[i] != prev) psum[i] = 1;
        prev = v[i];
    }
    psum[n] = prev;

    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;        
        g[a].push_back(b);
        g[b].push_back(a);
        
    }

    vector<int> visited(n+1);
    function<int(int)> dfs = [&](int curr){
        if(visited[curr]) return 0;
        visited[curr] = 1;        
        int cnt = psum[curr];
        for(auto e : g[curr]) cnt ^= dfs(e);        
        return cnt;
    };    

    for(int i = 0; i <= n; i++){
        if(dfs(i)){            
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}