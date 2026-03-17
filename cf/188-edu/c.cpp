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
ll a, b, c, m;
#define int ll

ll calc_pair(ll x, ll y){
    int g = gcd(x, y);
    
    ll yg = y/g;
    return m/(x*yg);
}

ll calc_triple(int x, int y, int z){
    int g = gcd(x, y);

    ll yg = y/g;

    return calc_pair(x*yg, z);
}

void solve(){
    cin >> a >> b >> c >> m;

    ll ab = calc_pair(a, b);
    ll ac = calc_pair(a, c);
    ll bc = calc_pair(b, c);
    ll abc = calc_triple(a, b, c);

    //dbg(ab, ac, bc, abc, m/a, m/b, m/c);

    ll ans_a = 2*abc + 3*(ab - abc) + 3*(ac - abc) + 6*((m/a) - ab - ac + abc);
    ll ans_b = 2*abc + 3*(ab - abc) + 3*(bc - abc) + 6*((m/b) - ab - bc + abc);
    ll ans_c = 2*abc + 3*(bc - abc) + 3*(ac - abc) + 6*((m/c) - bc - ac + abc);

    cout << ans_a << " " << ans_b << " " << ans_c << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}