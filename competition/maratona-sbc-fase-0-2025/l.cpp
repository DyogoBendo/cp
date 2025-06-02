#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    ll m;
    cin >> m;
    m *= 8e6;

    int msb = __builtin_clzll(m);
    int ans = 63 - msb;

    if(1 << ans != m) ans++;

    cout << ans << endl;
}