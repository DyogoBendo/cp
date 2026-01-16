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

const int MAXX = 1e6 + 10;

ll get_val(ll x){
    if(x % 3) return -1;
    x /= 3;

    ll lo = 0, hi = 1e9 + 10;

    while(lo < hi){
        ll m = (hi - lo) / 2 + lo;

        if(m*m < x) lo = m+1;
        else hi = m;
    }

    if(lo*lo != x) return -1;
    return lo;
}

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<int> v(MAXX);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[x/2] = i+1;
    }

    while(q--){
        ll d1, d2, d3;
        cin >> d1 >> d2 >> d3;

        ll x1 = get_val(d1);
        ll x2 = get_val(d2);
        ll x3 = get_val(d3);

        ll tot = x1 + x2 + x3;

        dbg(tot);

        if(tot >= MAXX or min({x1, x2, x3}) < 0) cout << -1 << endl;
        else cout << (v[tot] ? v[tot] : -1) << endl;
    }
}