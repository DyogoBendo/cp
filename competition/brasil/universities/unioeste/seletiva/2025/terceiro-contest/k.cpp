#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int l, n;
    cin >> l >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int mn = 0, mx = 0;

    for (int i = 0; i < n; i++)
    {
        int dst = min(v[i], l - v[i]);
        mn = max(mn, dst);
        mx = max({mx, v[i], l-v[i]});
    }

    cout << mn << " " << mx << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}