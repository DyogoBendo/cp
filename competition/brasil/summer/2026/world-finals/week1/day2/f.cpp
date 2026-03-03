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

ll get_sqrt(ll x){
    ll a = sqrt(x);
    if(a * a != x) return -1;
    return a; 
}

ll c1(ll x){
    if(x % 4) return -1;

    ll k = x/4;

    ll op = 4LL*k*k - 1;

    return op;
}

ll c2(ll x){
    x = x + 1;
    if(x % 4) return -1;
    x /= 4;

    x = get_sqrt(x);
    if(x == -1) return -1;

    return 4*x;
}

ll c3(ll x){
    x = x-1;
    if(x & 1) return -1;
    x/= 2;

    if(x <= 1) return -1;
    return 2*x*(x+1);
}

ll c4(ll x){
    if(x & 1) return -1;
    x/= 2;

    ll lo = 1, hi = 1e9;

    while(lo < hi){
        ll m = (hi - lo) / 2 + lo;

        if(m*(m+1) < x){
            lo = m + 1;
        } else{
            hi = m;
        }
    }    

    if(lo == 1) return -1;
    if(lo*(lo+1) == x){
        return 2*lo + 1;
    }
    return -1;
}

ll calc(ll x){    
    ll x1 = c1(x);
    ll x2 = c2(x);
    ll x3 = c3(x);
    ll x4 = c4(x);

    ll tot = 0;
    tot += (x1 != -1);
    tot += (x2 != -1);
    tot += (x3 != -1);
    tot += (x4 != -1);
    return tot;
}

signed main(){
    darvem;

    ll n;
    cin >> n;

    ll ans =0;
    for(ll i = 1; i * i <= n; i++){
        if(n % i) continue;
        
        ll j = n / i;
 
        ans += calc(i);        
        if(j != i) ans += calc(j);
    }    

    cout << ans << endl;
}