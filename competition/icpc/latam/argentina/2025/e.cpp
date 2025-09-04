#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif


namespace sparse{
    const int MAX = 4e5+123;
    const int MAX2 = 23;
    pair<int, int> m[MAX2][MAX];
    int n;
    void build(int n2, vector<pair<int, int>> v){
        n = n2;
        for (int i = 0; i < n; i++) m[0][i] = v[i];
        for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
        m[j][i] = min(m[j-1][i], m[j-1][i+(1<<(j-1))]);
    }
    int query(int a, int b){
        if (a > b) swap(a, b);
        int j = __builtin_clz(1) - __builtin_clz(b-a+1);
        return min(m[j][a], m[j][b-(1<<j)+1]).second;
    }
}


const int mx = 3e5+123;
vector<int> g [mx], vis (mx, -1), lca (mx);
vector<ll> dp (mx), t (mx);

vector<pair<int, int>> tour;
vector<int> toin (mx), tout (mx), depth (mx);
void euler_tour(int u, int p, int d){
    depth[u] = d;
    toin[u] = sz(tour);
    tour.push_back({d, u});
    for (auto v: g[u]) if (v != p) {
        euler_tour(v, u, d+1);
        tour.push_back({d, u});
    }
    tout[u] = sz(tour);
}

int get_lca(int a, int b){
    return sparse::query(toin[a], toin[b]);
}

ll Vans = 0;
int Tans = mx;

void check(int d){
    ll v = dp[d];
    int dis = d-depth[lca[d]];
    if (v > Vans || (v == Vans && dis <= Tans)) Vans = v, Tans = dis;
}

void dfs(int u, int p, int d, int root){
    if (t[u] && vis[d] != root){
        vis[d] = root;
        dp[d] = 0;
        lca[d] = u;
    }
    if (t[u]){
        lca[d] = get_lca(lca[d], u);
        dp[d] += t[u];
    }
    dbg(u, p);
    dbg(dp[d]);
    dbg(lca[d]);
    check(d);
    for (auto v: g[u]) if (v != p) {
        dfs(v, u, d+1, root);
    }
}

void solution(){
    int n;
    cin >> n;
    for (int i=2; i<=n; i++) cin >> t[i];
    for (int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    euler_tour(1, 1, 0);
    sparse::build(sz(tour), tour);
    for (auto u: g[1]){
        dfs(u, 1, 1, u);
    }
    cout << Vans << ' ' << Tans+1 << '\n';
}

signed main(){
    fastio;
    int cases=1;
    //cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    return 0;
}