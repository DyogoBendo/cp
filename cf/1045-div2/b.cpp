#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll m = max(k - 1, 2LL);
    if(k == 2){
        for(int i = 0; i < n; i++){
            while(v[i] % 3 != 0) v[i] += 2;
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i =0; i < n; i++){
        ll x = v[i] % m;
        ll diff = (m - x) % m;
        cout << v[i] + (diff * k) << " ";
    }   
    cout << endl;

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}