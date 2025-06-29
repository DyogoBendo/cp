#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

ll read(ll x){
    cout << "buf[" << x << "]" << endl;
    cout.flush();

    ll k;
    cin >> k;
    return k; 
}

signed main(){    

    ll cur = -1, cnt = 0, pos = 0, prev = 0;
    while(cur != 0){
        prev = pos;
        cur = read(1LL << cnt);
        pos = 1LL << cnt;
        cnt++;
    }

    ll lo = prev + 1, hi = pos;

    while(lo < hi){
        ll m = (hi - lo) / 2 + lo;
        ll x = read(m);

        if(x) lo = m + 1;
        else hi = m;
    }

    cout << "strlen(buf) = " << hi << endl;
    cout.flush();
}