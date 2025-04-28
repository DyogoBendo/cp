#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll n;
    cin >> n;

    int ans = 0;
    for (ll i = 2; i * i <= n; i++)
    {        
        ll curr = i;
        while(n % curr == 0){
            ans++;
            n /= curr;
            curr *= i;
        }        
        while(n % i == 0) n/= i;                    
    }
    if(n > 1) ans ++;
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    // cin >> t;

    while(t--) solve();
}