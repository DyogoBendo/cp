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

const int MOD =  998244353;

ll calc(ll n, ll k, ll limit){            
    if(k == 1) return n <= limit;
    
    ll ans = 0;
    for(int i = 2; i < k+1; i++){
        if(n%i) continue;
        if(n/i > limit) continue;        
        ll add = calc(n - n/i, k-1, n/i);        
        if(n % i == 0) ans = (ans + add) % MOD;
    }        
    return ans % MOD;
}

signed main(){
    darvem;
    ll n, k;    
    cin >> n >> k;

    cout << calc(n, k, n) % MOD << endl;
}