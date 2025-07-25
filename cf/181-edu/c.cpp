#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    ll l, r;
    cin >> l >> r;

    vector<int> primes = {2, 3, 5, 7};

    ll sub = 0;
    for(int i = 1; i < 16; i++){
        int x = 1, op =0;
        for(int k = 0; k < 4; k++){
            if(i&(1<<k)){
                x*= primes[k];
                op ^= 1;
            } 
        }

        ll st = ((x - (l%x)) % x + l);        

        ll tot= st <= r ? (r-st) / x + 1 : 0;        

        if(op) sub += tot;
        else sub -= tot;
    }

    cout << (r-l+1) - sub << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}