#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if(n > m){
        cout << 0 << endl;
        return;
    }

    ll ans= 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = ans * abs(v[i] - v[j])  % m;
        }
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}