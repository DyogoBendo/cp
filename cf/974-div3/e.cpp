#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define pb push_back
 
typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()
 
void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
 
const int mx = 2e5+5;
const ll inf = 1e16;
vector<pair<int, int>> conn[mx];
vector<int> horse(mx);
 
vector<ll> dijkstra(int st, int n){
    // dist, horse, vertex
    vector<vector<ll>> dist (2, vector<ll>(n+1, inf));
    priority_queue<tuple<ll, int, int>> q;
    q.push({0, 0, st});
    while (!q.empty()){
        auto [d, h, v] = q.top(); q.pop();
        d = -d;
        if (d > dist[h][v]) continue;
        cout << "d: " << d << " h: " << h << " v: " << v << endl;
        dist[h][v] = d;
        h = (h | horse[v]);
        for (auto [u, w]: conn[v]){
            if (h) w /= 2;
            if (w+d > dist[h][u]) continue;
            dist[h][u] = w+d;
            q.push({-dist[h][u], h, u});
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[0][i + 1] << " " << dist[1][i + 1] << endl;
    }
    
    vector<ll> ans (n+1);
    for (int i=1; i<=n; i++) ans[i] = min(dist[0][i], dist[1][i]);
    return ans;
}
 
int solution(int testcase){
    int n, m, h;
    cin >> n >> m >> h;
    for (int i=0; i<h; i++){
        int a;
        cin >> a;
        horse[a] = 1;
    }
    for (int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        conn[a].push_back({b, w});
        conn[b].push_back({a, w});
    }
    vector<ll> d1 = dijkstra(1, n);
 
    return testcase;
}
 
signed main(){
    fastio;
    int n=1;
    cin >> n;
    for (int i=0; i<n; i++){
        solution(i);
    }
}