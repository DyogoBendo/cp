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

const int MOD = 1e9 + 7;

signed main(){
    darvem;

    ll n, m, l, r;
    cin >> n >> m >> l >> r;

    if(r < l){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    if(l == 1){
        ans += (m-1) * n % MOD;
        ans += (n-1) * m % MOD;
        ans %= MOD;
    }    

    vector<vector<ll>> prime_factors(r+1);

    for(int i = 2; i <= r; i++){
        if(prime_factors[i].empty()){
            for(int j = i; j <= r; j+= i) prime_factors[j].push_back(i);
        }
    }

    ll l2 = l*l;
    ll r2 = r*r;

    auto get_sq_floor = [&](ll x){
        if(x <= 0) return 0LL;

        ll s = sqrt(x);
        while(s*s < x) s++;
        while(s*s > x) s--;
        return s;
    };  

    auto get_sq_ceil = [&](ll x){
        if(x <= 0) return 0LL;

        ll s = sqrt(x);
        while(s*s > x) s--;
        while(s*s < x) s++;
        return s;
    };  
    
    auto pa2 = [&](ll a, ll b){
        ll t = (b - a) + 1;
        ll res = (t * (b + a) / 2); 
        dbg(a, b, t, res);
        return  res % MOD;
    };

    dbg(ans);
    for(ll u = 1; u*u < r2 and u < n; u++){
        ll a = max(1LL, get_sq_ceil(l2 - u*u));
        ll b = min(m-1, get_sq_floor(r2 - u*u));
        if(b < a) continue;

        ll cnt = 2* (n - u) % MOD;
        ll tot = m * (b - a + 1) % MOD;
        dbg(cnt, tot);
        tot -= pa2(a, b);
        tot += MOD;
        tot %= MOD;

        dbg(u, a, b, tot);
        
        for(int mask = 1; mask < (1 << sz(prime_factors[u])); mask++){
            ll cur_val = 1;
            for(int j = 0; j < sz(prime_factors[u]); j++){
                if((mask >> j) & 1) cur_val *= prime_factors[u][j];
            }
            ll parity = __builtin_popcount(mask) & 1;

            ll change = 0;
            ll start = (a + cur_val - 1) / cur_val;
            ll end = b / cur_val;

            if(start > end) continue;

            ll cnt_mul = end - start + 1;

            change += m * cnt_mul;
            change %= MOD;

            change -= (cur_val * pa2(start, end)) % MOD;
            change += MOD;
            change %= MOD;
            change %= MOD;

            if(parity){
                tot -= change;
                tot += MOD;
            } else tot += change;
            tot %= MOD;
        }
        tot *= cnt;
        tot %= MOD; 

        ans += tot;
        ans %= MOD;
    }

    cout << ans << endl;
}