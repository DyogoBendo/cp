#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    ll x = 0, tmp, mx = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        x += tmp;
        mx = max(mx, tmp);
    }
    
    cout << (x % 2 || mx > x - mx ? "NO" : "YES") << endl;
}


signed main(){
    darvem;
    int t = 1;
    

    while(t--) solve();
}