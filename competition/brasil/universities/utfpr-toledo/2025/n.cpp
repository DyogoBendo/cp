#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const ll MOD = 998244353;

ll sum(ll x){
    return (x)* (x + 1) / 2 % MOD;
}

ll sum2(ll x){
    return ((x) * (x + 1) * (2*x + 1)) / 6 % MOD;
}

signed main(){
    darvem;

    ll a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);

    ll tot = sum(a) * sum(b);
    ll quad = a * a * b - a*(sum(a)) - b * (sum(b)) + sum2(a);

    cout << tot - quad << endl;
}