#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long

using namespace std;
const int INF = 1e9;
const int MAXN = 1e5 + 10;
const int MAXK = 30;
array<array<int, MAXK>, MAXN> dp, dpMin;
array<int, MAXN> depth;

typedef struct dsu{
    vector<int> id, sz;
    dsu(int n) : id(n), sz(n, 1) {iota(id.begin(), id.end(), 0);}
    int find(int a) {return a == id[a] ? a : id[a] = find(id[a]);}
    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
    }
} DSU;

vector<vector<pair<int,int>>> kruskal(int n, vector<tuple<int, int, int>> &edges){
    DSU dsu(n);
    sort(edges.begin(), edges.end());
    vector<vector<pair<int, int>>> tree(n);

    for (auto &[w, v, u] : edges)
    {                
        if(dsu.find(u) == dsu.find(v)) continue;
        dsu.unite(u, v);        
        tree[u].push_back({v, -w});
        tree[v].push_back({u, -w});
    }
    return tree;
}

void dfs(vector<vector<pair<int, int>>> &tree, int v, int p, int w){    
    depth[v] = depth[p] + 1;
    dp[v][0] = p; // the 2^0(1) ancestor of v is p
    dpMin[v][0] = w; // the min value in the path from v to its parent is w
    for (int k = 1; k < MAXK; k++)
    {
        dp[v][k] = dp[dp[v][k - 1]][k-1];
        dpMin[v][k] = min(dpMin[v][k-1], dpMin[dp[v][k-1]][k-1]);
    }

    for (auto [u, curr_w] : tree[v]){
        if (u != p) dfs(tree, u, v, curr_w); 
    } 
}

int calcPath(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);

    int ans = INF;

    for (int k = MAXK - 1; k >= 0; k--){
        int nxt = dp[x][k];
        if(depth[nxt] >= depth[y]){
            ans = min(ans, dpMin[x][k]);
            x = nxt;
        }
    } 
        
    if(x == y) return ans;

    for (int k = MAXK - 1; k >= 0; k--){
        if(dp[x][k] != dp[y][k])
        {
            ans = min({dpMin[x][k], dpMin[y][k], ans});
            x = dp[x][k];
            y = dp[y][k];
        }
    } 
    
    return min({ans, dpMin[x][0], dpMin[y][0]});
}

void solve(){
    int n, b;
    cin >> n >> b;
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < b; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;y--;
        edges.push_back({-z, x, y});
    }
    
    vector<vector<pair<int , int>>> tree = kruskal(n, edges);   
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXK; j++)
        {
            dp[i][j] = -1;
            dpMin[i][j] = INF;
        }        
    }
     

    dfs(tree, 0, 0, INF);

    int c;
    cin >> c;
    
    while(c--){
        int x, y;
        cin >> x >> y;
        x--;y--;

        cout << calcPath(x, y) << '\n';
    }
    
}

signed main(){
    flash;
    int t = 1;    

    while(t--) solve();
}