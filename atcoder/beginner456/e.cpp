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
    int n, m, w;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> w;

    vector<string> days(n);
    for(int i = 0; i < n; i++) cin >> days[i];
    vector<vector<int>> visited_prev(n, vector<int>(w));

    set<pair<int, int>> active;

    bool found = false;
    function<void(int, int)> dfs = [&](int curr, int day){
        if(days[curr][day] == 'x') return;        

        if(visited_prev[curr][day]){
            return;            
        }

        if(active.count({curr, day})){
            found= true;
            return;
        }        
        active.insert({curr, day});

        for(auto e : g[curr]){            
            dfs(e, (day + 1) % w);
            visited_prev[e][(day+1) % w] = 1;
            if(found) return;
        }        
        dfs(curr, (day+1) % w);

        active.erase({curr, day});
        visited_prev[curr][day] = 1;
    };

    for(int i = 0; i < n; i++){
        if(!visited_prev[i][0] and !found){
            dbg(i);            
            dfs(i, 0);                             
        } 
    }

    cout << (found ? "Yes" : "No") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}