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

void solve(){
    ll zeros, ones, ors;
    cin >> zeros >> ones >> ors;

    if(ones == 0){
        cout << 0 << endl;
        return;
    }    

    if(ors == 0 or zeros == 0){
        cout << ones-1 << endl;
        return;
    }    

    ll ans = 0;
    ll min_using_num = min({zeros, ones});    

    ll can_or = 2*min_using_num-1;    

    ll min_or_op = (min( ors, can_or) + 1) / 2;

    
    ll add = 2*min_or_op-1;
    dbg(min_using_num, can_or, min_or_op, add);

    zeros -= min_or_op;
    ones -= min_or_op;
    ors -= add;
    ans += add;

    ans += ones;

    if(ors and zeros) ans++;    

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}