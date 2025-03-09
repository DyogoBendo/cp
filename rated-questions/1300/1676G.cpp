#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

void solve(){
    string s;
    int n, ans = 0;
    cin >> n;    

    vector<vector<int>> tree(n);
    
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x --;
        tree[x].push_back(i);
    }
    cin >> s;

    function<int(int)> dfs = [&](int curr){
        int x = s[curr] == 'W' ? -1 : 1;    

        for (auto c : tree[curr])
        {
            x += dfs(c);
        }    
        ans += x == 0;    
        return x;
    };

    dfs(0);
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}