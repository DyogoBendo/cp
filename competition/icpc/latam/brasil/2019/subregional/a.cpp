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

    int n, m, k;
    cin >> m >> n >> k;

    vector<vector<int>> edges(2);    
    vector<tuple<int, int, int>> prev;

    auto check_circles = [&](int i, int j){
        auto [xi, yi, si] = prev[i];
        auto [xj, yj, sj] = prev[j];

        ll dx = xi-xj;
        ll dy = yi - yj;
        return (dx*dx + dy*dy <= (si + sj) * (si + sj));
    };
   
    for(int i = 0; i < k; i++){
        int x, y, s;
        cin >> x >> y >> s;
        edges.push_back(vector<int>());
        if(x - s <= 0 or y + s >= n) edges[0].push_back(i+2), edges[i+2].push_back(0);
        if(x + s >= m or y - s <= 0) edges[1].push_back(i+2), edges[i+2].push_back(1);

        prev.push_back({x, y, s});
        for(int j = 0; j < i; j++){
            if(check_circles(i, j)) edges[i+2].push_back(j+2), edges[j+2].push_back(i+2);
        }
    }

    queue<int> q;
    vector<int> visited(k+2);
    q.push(0);

    while(!q.empty()){
        int x = q.front(); q.pop();
        if(visited[x]) continue;
        visited[x] = 1;

        for(auto e : edges[x]){
            if(!visited[e]) q.push(e);
        }
    }

    cout << (visited[1] ? "N" : "S") << endl;
}