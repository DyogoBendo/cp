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

ll x, y, k;
ll check(ll p){
    for(int i = 0; i < x; i++){
        p -= p/y;
    }
    return p >= k;
}

void solve(){
    cin >> x >> y >> k;

    ll lo = 0, hi = 1e12+1;

    while(lo < hi){
        ll mid = (hi - lo) / 2 + lo;

        if(check(mid)){
            hi = mid;
        } else{
            lo = mid + 1;
        }
    }

    if(hi == 1e12+1) cout << -1 << endl;
    else cout << hi << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}