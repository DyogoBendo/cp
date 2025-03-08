#include <bits/stdc++.h>

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

#define int long long

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for(int &e : v) cin >> e;

    map<pair<int, int>, int> p;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int xp =( x - v[i] % x) % x;
        int yp = v[i] % y;
        ans += p[{v[i] % x,v[i] % y}];
        p[{xp, yp}]++;
    }    
    
    cout << ans  << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}