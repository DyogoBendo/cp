#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> respect(n);
    vector<vector<int>> tree(n);

    int root = -1;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        if(a >=0) tree[a].push_back(i);
        else root = i;
        respect[i] = b;
    }

    vector<int> removable;

    function <void(int)> dfs = [&](int curr){
        int check = respect[curr];
        for (auto u : tree[curr])
        {
            check &= respect[u];
            dfs(u);
        }        
        if(check) removable.push_back(curr);
    };
    
    dfs(root);
    sort(removable.begin(), removable.end());

    for (int x: removable)
    {
        cout << x+1 << ' ';
    }
    if(removable.size() == 0) cout << -1;
    cout << endl;
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}