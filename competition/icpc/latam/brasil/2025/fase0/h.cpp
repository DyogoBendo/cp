#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    ll x;
    cin >> x;

    int msb = 63 - __builtin_clzll(x);

    if(x == 1){
        cout << 1 << endl;
        return 0;
    }

    if(x == (1LL << msb)){
        cout << x-1 << endl;
        return 0;
    }

    int l = 0, r = msb;


    ll ans = 0;
    while(l <= r){
        ll addr = 1LL << r;
        ll addl = 1LL << l;         

        if(l != r && ans + addr + addl <= x){
            ans += addr + addl;
        } else if(l == r && ans + addr <= x){
            ans += addr;
        }
        l++;
        r--;
    }
    cout << ans << endl;    
}