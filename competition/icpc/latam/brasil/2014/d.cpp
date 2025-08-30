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

    vector<vector<tuple<int, int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c, i});
        g[b].push_back({a, c, i});
    }

    // identificar ciclos
    vector<int> visited_v(n);
    vector<int> visited_e(m);
    vector<pair<int, int>> s;
    vector<int> cycles;
    vector<int> cycle_group(n, -1);
    function<void(int, int)> dfs = [&](int curr, int p){
        if(visited_v[curr]){            
            // temos um ciclo            
            int cycle_sz = 0;
            int i = s.size() - 1;
            while(1){
                auto [u, e]  = s[i];             
                cycle_sz += e;
                cycle_group[u] = cycles.size();
                if(u == curr){                    
                    break;
                } 
                i--;
            }            
            cycles.push_back(cycle_sz);
            return;
        }   
        visited_v[curr] = 1;

        for(auto [u, w, idx] : g[curr]){
            if(visited_e[idx])continue;
            visited_e[idx] = 1;
            s.push_back({curr, w});
            dfs(u, curr);
            if(s.size()) s.pop_back();
        }
    };

    for(int i = 0; i < n; i++){
        if(!visited_v[i]) dfs(i, i);
    }

    auto solve = [&](int st, int size){
        const int INF = 1e9;
        vector<int> distance(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> pq;
            
        pq.push({0, st});
        int ans = INF;
        while(!pq.empty()){
            auto [dst, curr] = pq.top(); pq.pop();            
            if(dst >= distance[curr]) continue;

            if(cycle_group[curr] != -1 && cycles[cycle_group[curr]] >= size){
                ans = min(ans, cycles[cycle_group[curr]] + 2*dst);                
            }

            distance[curr] = dst;

            for(auto [u, w, _] : g[curr]){                
                pq.push({dst + w, u});
            }
        }
        if(ans == INF) return -1;
        return ans;
    };

    int t;
    cin >> t;
    while(t--){
        int x, c;
        cin >> x >> c;
        x--;

        cout << solve(x, c) << endl;
    }

}