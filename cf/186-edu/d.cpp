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

const int MOD = 998244353;

ll fat[65];

ll fast_expo(ll x, ll k){
    ll ans = 1;
    while(k){
        if(k & 1) ans = (ans * x) % MOD;
        x = (x *x) % MOD;
        k >>= 1; 
    }
    return ans;
}

ll inv(ll x){
    return fast_expo(x, MOD-2);
}

ll comb(ll n, ll k){
    return fat[n] * (inv(fat[n-k]) * inv(fat[k]) % MOD) % MOD;
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    int zero;
    cin >> zero;

    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    } 

    int cnt_mx = 0, cnt_prev = 0;
    for(int i = 0; i < n; i++){
        if(v[i] < mx - 1){
            zero -= mx-1-v[i];
            v[i] = mx - 1;
        }

        if(v[i] == mx) cnt_mx++;
        else cnt_prev++;
    }
    if(zero < 0){
        cout << 0 << endl;
        return;
    }


    int can_go = min(cnt_prev, zero);

    ll ans = ((fat[cnt_mx + can_go] * comb(cnt_prev, can_go)) % MOD * fat[cnt_prev - can_go]) % MOD;
    cout << ans << endl;
}


signed main(){
    darvem;
    fat[0] = 1;
    for(int i = 1; i < 64; i++) fat[i] = fat[i-1]* i % MOD;

    int t = 1;
    cin >> t;

    while(t--) solve();
}