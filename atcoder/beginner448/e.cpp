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

const int P = 10007;
const int MAXK = 50;
ll mod;

ll dp[MAXK];

ll fast_expo(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e % 2) ret = ret * b % mod;
        e /= 2, b = b * b % mod;
    }
    return ret;
}

void init(){
    dp[0] = 1;
    ll p10 = 10;

    for(int i = 1; i < MAXK; i++){
        dp[i] = ((dp[i-1] * p10) % mod + dp[i-1]) % mod;
        p10 = (p10 * p10) % mod;
        dbg(i, dp[i]);
    }
}

ll repunit(ll x){
    if(x == 0) return 0;

    ll k = 0;
    while(x >= (1LL << k)) k++;    
    k--;

    ll diff = x - (1LL << k);
    assert(diff >= 0);

    ll p10 = fast_expo(10, diff);

    dbg(x, k, diff, (1 << k));

    return (((dp[k] * p10) % mod) + repunit(diff)) % mod;
}

ll calc(ll d, ll x){        
    return (d * repunit(x)) % mod;    
}

void solve(){
    int k, m;
    cin >> k >> m;
    mod = P * m;
    dbg(mod);
    init();

    vector<pair<ll, ll>> v(k);
    for(int i = 0; i < k; i++) cin >> v[i].first >> v[i].second;

    ll acc10 = 0, tot = 0;
    for(int i = k-1; i >= 0; i--){
        dbg(i, acc10, tot);
        tot = ((calc(v[i].first, v[i].second) * fast_expo(10, acc10)) % mod + tot) % mod;
        acc10 += v[i].second;
    }

    cout << tot/m << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}