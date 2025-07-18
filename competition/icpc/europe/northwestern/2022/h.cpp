#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[--v].push_back(--u);
        tree[u].push_back(v);
    }

    int ans = 0;
    function<vector<int>(int, int)> dfs = [&](int curr, int p){
        vector<int> l, r;
        int cnt = 0;
        for (auto e : tree[curr])
        {
            if(e == p) continue;
            if(cnt == 0) l = dfs(e, curr);
            if(cnt == 1) r = dfs(e, curr);
            cnt++;
        }
        
        vector<int> merge;

        if(l.size() > r.size()) swap(l, r);

        merge.push_back(1);        
        for(int i = 0; i < r.size(); i++){
            if(i <= l.size()){
                int x=  r[i];
                if(i < l.size()) x += l[i];
                merge.push_back(x);
            } 
            else{                
                ans += r[i];
            } 
        }        
        return merge;
    };
    
    dfs(0, 0);

    cout << ans << endl;
}