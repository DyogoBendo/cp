#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    for(int i = 1; i < n; i+= 2){
        int l = i > 0 ? v[i-1] : 1e9+10;
        int r = i < n-1 ? v[i+1] : 1e9+10;
        int tot = 0;
        if(i > 0){
            ans += max(0LL, v[i-1] - v[i]);
            v[i-1] = min(v[i], v[i-1]);
            tot += v[i-1];
        } 
        if(i < n-1){
            ans+= max(0LL, v[i+1] - v[i]);
            v[i+1] = min(v[i], v[i+1]);
            tot += v[i+1];

            if(tot > v[i]){
                v[i+1] -= tot - v[i];
                ans += tot - v[i];
            }
        } 

    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}