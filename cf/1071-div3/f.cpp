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

void solve_first(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> color(n+1);

    queue<tuple<int, int, int>> q;

    vector<int> visited(n+1);
    visited[1] = 1;
    q.push({1, 0, 0});
    
    while(!q.empty()){
        auto [v, c, p] = q.front(); q.pop();
        color[v] = c;
        for(auto u : g[v]) if(!visited[u]){
            visited[u] = 1;
            q.push({u, (c+p) % 3, p^1});
        }
    }

    string s = "rgb";

    for(int i = 1; i <= n; i++) cout << s[color[i]];
    cout << endl;
}

void solve_second(){
    int q, m;
    cin >> q;
    while(q--){
        string s;
        cin >> m >> s;

        int r = 0, g = 0, b = 0, ri = 0, gi = 0, bi = 0;
        for(int i = 0; i < sz(s); i++){
            if(s[i] == 'r') r++, ri = i;
            else if(s[i] == 'g') g++, gi = i;
            else b++, bi = i;
        }

        if(r and g) cout << ri+1;
        else if(g and b) cout << gi +1;
        else cout << bi + 1;
        cout << endl;
    }
}


signed main(){
    darvem;
    string s;
    int t = 1;
    cin >> s >> t;

    if(s == "first") while(t--) solve_first();
    else while(t--) solve_second();
}