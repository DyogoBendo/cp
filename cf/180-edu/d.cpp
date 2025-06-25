#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    bool found = false;
    vector<pair<int, int>> ans;
    function<void(int, int, int)> dfs = [&](int curr, int p, int d){
        bool to_keep = false, found_root = false;
        if(tree[curr].size() == 2 && !found){            
            found = true;
            if(curr == 0){
                ans.push_back({curr, tree[curr][0]});
                dfs(tree[curr][0], curr, 1);
    
                ans.push_back({tree[curr][1], curr});
                dfs(tree[curr][1], curr, -1);
                found_root = true;
            } else{
                d *= -1;
            }        
        } 
        if(!found_root){            
            for (auto e : tree[curr])
            {
                if(e == p) continue;
                if(d == -1){
                    ans.push_back({curr, e});
                } else{
                    ans.push_back({e, curr});
                }
                dfs(e, curr, d*(-1));
            }
        }        
        
    };

    dfs(0, 0, 1);
    
    if(n > 2 && found){
        cout << "YES" << endl;
        for (auto a : ans)
        {
            cout << a.first+1 << " " << a.second+1 << endl;
        }        
    } else{
        cout << "NO" << endl;
    }
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}