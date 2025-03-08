#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int a, p, v;
    cin >> a >> p >> v;

    int x = v/2 * p;

    int diff = a - x;
    int total = p - (diff * 2 / v);

    cout << total << endl;
}

signed main(){
    flash;
    int t = 1;
    // cin >> t;

    while(t--) solve();
}