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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> visited(n+1), colored(n+1);
    function<tuple<bool, int, int>(int, int)> dfs = [&](int curr, int color){
        if(visited[curr]){
            if(color != colored[curr]) return make_tuple(true, 0, 0);
            return make_tuple(false, 0, 0);
        }
        visited[curr] = 1;
        colored[curr] = color;
       
        bool impossible = false;
        int cnt0 = (color== 0), cnt1= (color == 1);
        for(auto e : g[curr]){
            auto [ic, c0, c1 ] = dfs(e, color^1);
            impossible |= ic;
            cnt0 += c0;
            cnt1 += c1;
        }

        return make_tuple(impossible, cnt0, cnt1);
    };

    int tot = 0;
    for(int i = 1; i <=n; i++){
        if(!visited[i]){
            auto [pos, cnt0, cnt1] = dfs(i, 0);
            if(!pos) tot += max(cnt0, cnt1);
        } 
    }

    cout << tot << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}