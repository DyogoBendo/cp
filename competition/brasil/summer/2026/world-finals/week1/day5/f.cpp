#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

//#define DEBUG

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

ll calc_lo(ll k, ll p, ll n){
    ll num = n - (k*p) + k + p - 1;
    ll d = k;

    return num/d;
}

ll calc_hi(ll k, ll n){
    return n/k;
}

ll check(ll x, ll k, ll p, ll n){
    ll left = k*x + (x % k) * (x %p);
    return left == n;
}

void solve(){
    ll k, p, n;
    cin >> k >> p >> n;

    ll lo = calc_lo(k, p, n);
    ll hi = calc_hi(k, n);

    ll cnt = 0;
    for(ll i = lo; i <= hi; i++) cnt += check(i, k, p, n);

    cout << cnt << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++) solve();
}