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

const int MAXN = 1e5 + 100;
vector<pair<int, int>> tree[MAXN];
int subtree_sz[MAXN], heavy[MAXN], idx_heavy[MAXN], color[MAXN], tot_color[MAXN], cnt[MAXN], ans[MAXN];

void dfs_sz(int curr, int p){
    int s = 1;
    int mx = 0, hc = -1, idx_h = -1;
    for(auto [e, i] : tree[curr]) if(e != p){
        dfs_sz(e, curr);        
        s += subtree_sz[e];
        if(subtree_sz[e] > mx){
            mx = subtree_sz[e];
            hc = e;
            idx_h = i;
        }
    }
    heavy[curr] = hc;
    idx_heavy[curr] = idx_h;
    subtree_sz[curr] = s;
}

ll tot = 0;

ll calc(ll c){
    ll r = tot_color[c] - cnt[c];    
    return r * cnt[c];
}

void add_color(int c, int x){
    tot -= calc(c);
    cnt[c] += x;
    tot += calc(c);
}

void add_subtree(int curr, int p, int x){
    add_color(color[curr], x);
    for(auto [e, i] : tree[curr]) if(e != p){
        add_subtree(e, curr, x);
    }
}

void dfs_solve(int curr, int p, int idx, int keep){
    for(auto [e, i] : tree[curr]) if(e != p and e != heavy[curr]) dfs_solve(e, curr, i, 0);
    
    if(heavy[curr] != -1) dfs_solve(heavy[curr], curr, idx_heavy[curr], 1);
    
    add_color(color[curr], 1);
    for(auto [e, i] : tree[curr]) if(e != p and e != heavy[curr]) add_subtree(e, curr, 1);

    if(idx != -1) ans[idx] = tot;
    if(!keep) add_subtree(curr, p, -1);
}

signed main(){
    darvem;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> color[i];    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;v --;
        tree[u].push_back({v, i});
        tree[v].push_back({u, i});
    }

    for(int i = 0; i < n; i++) tot_color[color[i]]++;

    dfs_sz(0, 0);
    dfs_solve(0, 0, -1, 0);

    for(int i = 0; i < n-1; i++) cout << ans[i] << " ";
    cout << endl;
}