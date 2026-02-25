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

// so é possível gerar se o menor bit ativo de s é >= que menor bit ativo de m
bool is_possible(ll s, ll m){
    if(s == m) return true;

    while(s and m){
        int bs = s % 2;
        int bm = m % 2;

        if(bs and !bm) return false;
        if(bm and !bs) return true;

        s /= 2;
        m /= 2;
    }
    return true;
}

ll lst_bit(ll x){
    if(x == 0) return 0;
    ll ans = 63 - __builtin_clzll(x);
    return ans;
}

ll parear(ll s, ll m, ll &ans){
    ll cnt = lst_bit(s);
    m %= (1LL << (cnt+1));

    ll cntm = lst_bit(m);

    
    m <<= (cnt - cntm);
    dbg(s, m, cnt, cntm);
    ans += (1LL << (cnt - cntm));

    ll sub = (s & m);
    dbg(sub);
    return s - sub;
}


void solve(){
    ll s, m;
    cin >> s >> m;

    if(!is_possible(s, m)){
        cout << -1 << endl;
        return;
    }

    ll x = (s / m);
    ll r = (s % m) != 0;

    ll ans = x + r;

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}