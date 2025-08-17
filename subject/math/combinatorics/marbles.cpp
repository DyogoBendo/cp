#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll n, k;
    cin >> n >> k;

    ll curr = n - 1;
    ll ans = 1;
    int lst = 1;
    while(curr > max(k-1, n - k)){        
        ans *= curr;
        while(ans % lst == 0 && lst <= min(k-1, n - k)){            
            ans /= lst;
            lst++;
        }
        curr--;
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}