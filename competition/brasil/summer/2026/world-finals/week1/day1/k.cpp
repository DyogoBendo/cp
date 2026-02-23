#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

const int mxx = 1e6+123;
int fac[mxx];
vector<ll> primes;
void sieve(ll n){
    for (int i=1; i<n; i++) fac[i] = i;
    for (ll i=2; i<n; i++){
        if (fac[i] == i) primes.push_back(i);
        for (auto p: primes){
            if (i*p >= n) break;
            fac[i*p] = p;
            if (i%p == 0) break;
        }
    }
}

vector<ll> nbrs;


ll mul(ll a, ll b, ll m){
    ll ret = a*b - ll((long double)1/m*a*b+0.5)*m;
    return ret < 0 ? ret+m : ret;
}

ll pow(ll x, ll y, ll m){
    if (!y) return 1;
    ll ans = pow(mul(x, x, m), y/2, m);
    return y%2? mul(x, ans, m) : ans;
}

bool prime(ll n){
    if (n < 2) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;
    ll r = __builtin_ctzll(n-1), d = n >> r;

    for (int a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
        ll x = pow(a, d, n);
        if (x == 1 or x == n-1 or a % n == 0) continue;

        for (int j=0; j<r-1; j++){
            x = mul(x, x, n);
            if (x == n-1) break;
        }
        if (x != n-1) return 0;
    }
    return 1;
}

int get_idx(ll x){
    return lower_bound(all(nbrs), x) - nbrs.begin();
}


void solve(){
    sieve(mxx);
    for (auto p: primes){
        ll x = p*p + 4;
        if (prime(x)) nbrs.push_back(x);
    }
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        ll l, r;
        cin >> l >> r;
        cout << get_idx(r+1) - get_idx(l) << '\n';
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}