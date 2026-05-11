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

#define int ll

void solve(){
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll lo = 0, hi = LLONG_MAX - 10;

    auto check = [&](ll x){
        ll op = k;

        for(int i = 0; i < n; i++){
            ll j = i+1;
            ll diff = x - v[i];
            if(diff <= 0) continue;

            if(diff/j > op) return false;

            ll r = (diff % j) != 0;

            ll cnt = diff/j + r;

            if(cnt > op) return false;
            op -= cnt;            
        }
        return true;
    };

    while(lo < hi){
        ll mid = (hi - lo) / 2 + lo;
        if(check(mid)) lo = mid+1;
        else hi = mid;
    }
    cout << hi-1 << endl;
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}