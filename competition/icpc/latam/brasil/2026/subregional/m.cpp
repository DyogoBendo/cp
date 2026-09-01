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

#define int ll
const int INF = 1e18;

signed main(){
    darvem;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<tuple<int, int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }

    priority_queue<tuple<int, int, int>> pq;

    vector<vector<int>> visited(n, vector<int>(k + 1, INF));

    pq.push({0, 0, 0});

    while(!pq.empty()){
        auto [cost, used, x] = pq.top(); pq.pop();
        cost = -cost;
        if(visited[x][used] < cost) continue;
        visited[x][used] = cost;
        if(x == n-1){
            cout << cost << endl;
            return 0;
        }

        for(auto [u, w, f] : g[x]){
            int cw = cost + w;
            int cf = cost + f;
            if(visited[u][used] > cw){
                visited[u][used] = cw;
                pq.push({-(cw), used, u});
            } 
            if(f != -1 and used < k and cf < visited[u][used+1]) pq.push({-cf, used + 1, u});
        }
    }
}