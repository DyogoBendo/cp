#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> danger(n);

    for (int i = 0; i < n; i++)
    {
        cin >> danger[i];
    }

    vector<vector<int>> tree(n);

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> ans(n);

    function<void(int, int, int)> dfs = [&](int curr, int p, int p2){
        int x = 0;
        ans[curr] = max(0LL, ans[p2] - danger[p]) + danger[curr];
        for (auto e : tree[curr])
        {
            if(e!= p) dfs(e, curr, p);
        }
        
    };
    
    dfs(0, 0, 0);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}