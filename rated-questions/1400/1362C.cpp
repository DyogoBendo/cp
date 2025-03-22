#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll n;
    cin >> n;

    ll ans =0;   
    ll x = 1; 
    for (ll i = 0; i < 63; i++)
    {                
        if(x > n) break;        
        ans +=i+ 1;
        if(i < 62){
            ll k = n - x;                            
            ans += (ll) (i+1) * (k/(x*2));
        }    
        x *= 2;    
    }
    cout << ans << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}