#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    vector<int> biggest(n);

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        int curr = 0;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
            mx = max(mx, x);
            curr = max(x, curr);
        }
        biggest[i] = curr;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int add = mx - biggest[i];
        int sz = (int) v[i].size();

        ans += sz * add;
    }
    
    cout << ans << endl;
    
}

signed main(){
    int t;
    t = 1;

    while(t--) solve();
}