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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<ll> cnta(n+1), cntb(n+1);
    ll remove = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];            
        cnta[a[i]]++;
        cntb[b[i]]++;
    } 

    ll ans = ((n) * (n-1) * (n-2)) / 6;
    for(int i = 0; i < n; i++){
        ll xa = cnta[a[i]] - 1;
        ll xb = cntb[b[i]] - 1;

        dbg(xa, xb);

        // 2 iguais
        remove += xa * xb;

        dbg(remove);
    }
    cout << ans - remove << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}