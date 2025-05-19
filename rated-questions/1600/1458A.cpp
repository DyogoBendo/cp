#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll g = 0;
    for (int i = 1; i < n; i++)
    {
        g = gcd(g, a[i] - a[0]);
    }
    

    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >>x;        
        cout << gcd(g, x+a[0]) << " ";
    }
    cout << endl;
    
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}