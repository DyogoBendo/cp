#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll a, b, k;
    cin >> a >> b >> k;

    if(a > b) swap(a, b);

    if(b/gcd(b, a) <= k) cout << 1 << endl;
    else cout << 2 << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}