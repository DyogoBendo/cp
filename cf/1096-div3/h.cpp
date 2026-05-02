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
    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int ans = 0;

    vector<int> leaves_parity(n), remove_cost(n);
    
    function<void(int, int)> dfs = [&](int curr, int p){
        int tot_leaves = 0;
        bool is_leaf = true;
        int mx = 0;
        for(auto e : tree[curr]) if(e != p){
            is_leaf = false;
            dfs(e, curr);
            tot_leaves ^= leaves_parity[e];
            mx = max(mx, remove_cost[e]);
        }
        if(is_leaf) tot_leaves = 1;

        leaves_parity[curr] = tot_leaves;        

        if(tot_leaves) ans++, mx++;
        else mx--;

        remove_cost[curr] = mx;        

        dbg(curr, p, is_leaf, tot_leaves);
    };

    int root = 0;
    for(int i = 0; i < n; i++) if(sz(tree[i]) > 1) root = i;        

    dfs(root, root);
    
    dbg(root, ans, remove_cost[root]);
    if(leaves_parity[root]) ans -= remove_cost[root];

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}