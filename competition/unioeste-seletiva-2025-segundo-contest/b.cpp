#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    map<int, vector<int>> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x].push_back(i);
    }

    int ans = n + 1;
    for (auto p : m)
    {
        vector<int> v = p.second;
        for (int i = 0; i < v.size() - 1; i++)
        {
            ans = min(ans, v[i + 1] - v[i] + 1);
        }
        
    }
    
    if(ans == n + 1) cout << -1 << endl;
    else cout << ans << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    while(t--) solve();
}