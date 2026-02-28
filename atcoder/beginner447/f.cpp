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

    vector<vector<int>> tree(n+1);

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> dp(n+1), dp2(n+1), used_child(n+1);

    function<void(int, int)> dfs = [&](int curr, int p){
        int num_children = sz(tree[curr]) - (p != curr);
        
        if(num_children >= 2) dp[curr] = 1;                
        for(auto e : tree[curr]) if(e != p){
            dfs(e, curr);
            if(num_children > 2 and dp[e]){
                if(dp[e] + 1 >= dp[curr]){
                    dp2[curr] = dp[curr]; 
                    dp[curr] = dp[e] + 1;
                    used_child[curr] = e;
                } else if(dp[e] + 1 > dp2[curr]){
                    dp2[curr] = dp[e] + 1;
                }
            }
        }
    };

    dfs(1, 1);

    int ans = 0;
    function<void(int, int)> dfs2 = [&](int curr, int p){
        if(curr != p){
            int x = used_child[p] == curr ? dp2[p] : dp[p];            
            
            if(sz(tree[p]) - 1 == 2) x = 1;
            if(sz(tree[p]) - 1 < 2) x = 0;
                        
            if(sz(tree[curr]) > 2){
                if(x + 1 >= dp[curr]){
                    dp2[curr] = dp[curr];
                    dp[curr] = x + 1;
                    used_child[curr] = p;
                } else if(x + 1 > dp2[curr]){
                    dp2[curr] = x+1;
                }                
            } else if(sz(tree[curr]) == 2){
                dp[curr] = 1;
            }
        }
        ans = max(ans, dp[curr]);

        for(auto e : tree[curr]) if(e != p) dfs2(e, curr);
    };

    dfs2(1, 1);

    // for(int i = 1; i <= n; i++) dbg(i, dp[i], used_child[i], dp2[i]);

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}