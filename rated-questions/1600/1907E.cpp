#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

ll calc(ll d){
    ll ans = 0;

    for (int i = 0; i <= d; i++)
    {
        ans += (i + 1);
    }

    return ans;
}

void solve(){
    int n;

    cin >> n;

    ll ans = 1;

    while(n){
        ans *= calc(n%10);
        n/=10;
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}