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
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> value(n+1);
    vector<vector<int>> tree(n+1);

    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        value[x] = 1;
    }

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> bst(n+1), bst_child(n+1), second_bst(n+1), parent(n+1);

    function<int(int, int)> dfs = [&](int curr, int p){
        parent[curr] = p;
        int b1 = 0;
        int b2 = -1;
        int c1 = 0;
        for(auto e : tree[curr]) if(e != p){
            int x = dfs(e, curr);

            if(x >= b1){
                c1 = b1;
                b1 = x;
                b2 = e;
                
            } else if(x >= c1){
                c1 = x;
            }
        }

        bst_child[curr] = b2;
        second_bst[curr] = c1 + value[curr];
        return bst[curr] = b1 + value[curr]; 
    };

    
    dfs(1, 1);
    dbg("dfs1");
    for(int i = 1; i<=n; i++){
        dbg(i, bst[i], bst_child[i], second_bst[i]);
    } 

    function<void(int, int)> dfs2 = [&](int curr, int p){
        dbg(curr, bst_child[p], second_bst[p]);
        if(curr != p and bst_child[p] != curr){
            second_bst[curr] = bst[curr];
            bst[curr] = bst[p] + value[curr];
            bst_child[curr] = p;
        } else if(curr != p){
            if(second_bst[p] + value[curr] > bst[curr]){
                second_bst[curr] = bst[curr];
                bst[curr] = second_bst[p] + value[curr];
                bst_child[curr] = p;
            } else if(second_bst[p] + value[curr] > second_bst[curr]){
                second_bst[curr] = second_bst[p] + value[curr];
            }
        }

        dbg(bst_child[curr], bst[curr], second_bst[curr]);
        dbg("");
        for(auto e : tree[curr]) if(e != p){
            dfs2(e, curr);
        }
    };

    dfs2(1, 1);

    int mx = 0;
    for(int i = 1; i<=n; i++){
        mx = max(bst[i], mx);
    } 

    while(q--){
        int u;
        cin >> u;

        if(bst[u] == mx) cout << "JA" << endl;
        else cout << "NEIN" << endl;

    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}