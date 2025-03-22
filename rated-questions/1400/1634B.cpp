#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    // cout << "n: " << n << " x: " << x << " y: " << y << endl;
    int parity = x%2;
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        parity ^= curr % 2;
    }
    
    cout << (parity == y % 2 ? "Alice" : "Bob") << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}