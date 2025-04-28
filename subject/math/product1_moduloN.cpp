#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll n;
    cin >> n;

    int ans = 0;
    ll curr = 1;

    vector<int> v;
    for (ll i = 1; i < n; i++)
    {
        if(gcd(i, n) == 1){
            v.push_back(i);
            ans ++;
            curr = (curr * i) % n;
        }
    }
    
    if(curr != 1) ans -- ;
    cout << ans << endl;
    for (auto x : v)
    {
        if(x == curr && curr != 1) continue;
        cout << x << " ";
    }
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}