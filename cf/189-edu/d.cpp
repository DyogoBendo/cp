#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

ll MOD = 998244353;

pair<ll, ll> cnt(ll n){
    ll b = n/4;

    ll zero = b, one= b;
    if(n % 4 >= 1) one++;
    if(n % 4 >= 3) zero++;

    dbg(zero, one);
    return make_pair(zero % MOD, one % MOD);
}

void solve(){
    ll x, n;
    cin >> n >> x;

    auto [zero_before, one_before] = cnt(x-1);
    auto [zero_n, one_n] = cnt(n);

    ll zero_after = (zero_n - zero_before + MOD) % MOD;
    ll one_after = (one_n - one_before + MOD) % MOD;

    ll end_zero = ((zero_after*zero_before % MOD) + zero_after) % MOD;

    ll end_one = (one_after*one_before % MOD);

    dbg(zero_before, one_before, zero_after, one_after);

    cout << ( end_zero+ end_one) % MOD << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}