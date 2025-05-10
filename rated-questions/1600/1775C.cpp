#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll n, x;
    cin >> n >> x;
    int active = 0;
    ll ans = n, curr = 0;

    for (ll i = 0; i < 62; i++)
    {
        if(!((1LL << i) & n) && ((1LL << i) & x)){
            cout << -1 << endl;
            return;
        }
        if((1LL << i) & n){                    
            if(!((1LL << i) & x)){                
                ans = (1LL << (i + 1));   
                curr = 0;
            } else{
                curr += (1LL << i);
            }
        }
    }
    ans |= curr;    
    
    if((n&ans) != x or ans < n) cout << -1 << endl;
    else cout << ans << endl;    
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}