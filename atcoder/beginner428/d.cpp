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
#define int long long
const ll MAXX = 5e9;

int get_num_digits(ll x){
    int tot = 0;
    ll p10 = 1;
    while(p10 <= x){
        p10 *= 10;
        tot ++;
    }
    return tot;
}

ll calc(ll x){    
    ll l = 0, r = MAXX;
    while(l < r){
        ll m = (r - l) / 2 + l;        
        if(m * m > x) r = m;
        else l = m + 1;
    }    
    return r;
}

int ans(ll c, ll d){    
    int digits = get_num_digits(d);
    
    ll curr = c;
    ll p10 = 1;
    ll ans = 0;
    for(int i = 0; i < digits; i++){
        curr *= 10;
        ll l = calc(curr + min(p10, d) - 1);
        p10 *=10;
        ll r = calc(curr + min(p10-1, d));        
        ans += r - l;
    }    
    return ans;
}

void solve(){
    ll c, d;
    cin >> c >> d;
    
    cout << ans(c, c+d) - ans(c, c) << endl;
}


signed main(){    
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}