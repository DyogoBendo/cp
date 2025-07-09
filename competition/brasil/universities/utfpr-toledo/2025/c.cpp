#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    ll b, e, m;
    cin >> b >> e >> m;

    ll ans = 1;

    while(e){
        if(e % 2){
            ans = (ans * b) % m;
        }
        e /= 2;
        b = (b * b) % m;
    }
    cout << ans << endl;
}