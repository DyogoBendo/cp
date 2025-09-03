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

const int MAXN = 2e5+10;
const int MAXL = 19;

int dp[MAXN][MAXL];

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;    

    vector<vector<int>> tree(n+1);

    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;        
        tree[x].push_back(i);
        dp[i][0] = x;
    }
    for(int i = 1; i < MAXL; i++){
        for(int j = 1; j <= n; j++){            
            dp[j][i] = dp[dp[j][i-1]][i-1];            
        }
    }

    vector<int> depth(n+1);
    function<void(int, int)> dfs = [&](int curr, int d){
        depth[curr] = d;
        for(auto e : tree[curr]) dfs(e, d+1);
    };

    dfs(1, 0);

    function<int(int, int)> lca = [&](int x, int y){        
        if(depth[x] != depth[y]){            
            if(depth[x] > depth[y]) swap(x, y);
            while(depth[y] > depth[x]){
                int diff = depth[y] - depth[x];                
                int bit = 31 - __builtin_clz(diff);                
                y = dp[y][bit];
            }
        }
        if(x == y) return x; // mesmo no
        if(dp[x][0] == dp[y][0]) return dp[x][0]; // mesmo pai            

        int lo = 0, hi = MAXL;        
        while(lo < hi){
            int m = (hi - lo) / 2 + lo;
            if(dp[x][m] == dp[y][m]){
                hi = m;
            } else{
                lo = m + 1;
            }
        }        
        x = dp[x][hi-1];
        y = dp[y][hi-1];
        return lca(x, y);
    };

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}