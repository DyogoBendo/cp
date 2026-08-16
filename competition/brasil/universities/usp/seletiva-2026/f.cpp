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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> tree(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> queries(q);
    for(int i = 0; i < q; i++) cin >> queries[i];    

    vector<ll> ans(q);

    function<map<int, int>(int, int, int)> dfs = [&](int curr, int p, int d){        
        map<int, int> bst;     
        if(sz(tree[curr]) == 1) bst[d]++;   
        for(auto c : tree[curr]) if(c != p){
            auto child = dfs(c, curr, d+1);
            if(sz(child) > sz(bst)) swap(bst, child);
            
            for(auto [x, y] : child){
                for(int j = 0; j < q; j++){
                    int dist = queries[j];                    
                    ans[j] += 1LL*y*bst[dist + 2*d - x];                    
                }
            }
            for(auto [x, y] : child) bst[x] += y;            
        }                         
        return bst;
    };

    dfs(0, 0, 0);
    for(int i = 0; i < q; i++) cout << ans[i] << endl;
}