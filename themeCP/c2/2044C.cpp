#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int m, a, b, c;
    cin >> m >> a >> b >> c;

    int x1 = min(m, a), x2 = min(m, b);
    int m1 = m - x1;
    int m2 = m - x2;
    int x3 = min(c, m1 + m2);

    cout << x1 + x2 + x3 << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}