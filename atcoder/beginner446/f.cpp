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

    vector<vector<int>> g(n+1), gi(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;        

        g[u].push_back(v);
        gi[v].push_back(u);
    }

    vector<int> visited(n+1);
    priority_queue<pair<int, int>> q;
    vector<vector<int>> depens_on(n+1);

    q.push({-1, 1});
    visited[1] = 1;

    while(!q.empty()){
        auto [cost, x] = q.top(); q.pop();        
        cost = -cost;
        depens_on[cost].push_back(x);

        for(auto e : g[x]) if(!visited[e]){
            visited[e] = cost;            
            q.push({-max(cost, e), e});
        }
    }

    int mn_not_visited = n+1;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            mn_not_visited = i;
            break;
        } 
    }

    vector<int> ans(n+1);
    // for(int i = n; i >= mn_not_visited; i--) ans[i] = -1;
    
    int curr_remove = 0;

    vector<int> cnt(n+1);

    for(int i = n; i >= 1; i--){
        dbg(i, mn_not_visited, curr_remove);
        if(!visited[i] or i >= mn_not_visited){
            ans[i] = -1;
        } else{
            ans[i] = curr_remove;
        }

        for(auto e : g[i]) if(e > i) {
            cnt[e] --;
            if(cnt[e] == 0) curr_remove--;
        }
        
        for(auto e : gi[i]) if(e < i) {            
            cnt[i] ++;
        }
        if(cnt[i]) curr_remove++;

        for(auto e : depens_on[i]){
            mn_not_visited = min(e, mn_not_visited);
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}