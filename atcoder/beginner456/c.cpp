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

ll calc(ll x){
    return ((x * (x + 1)) / 2) % MOD;
}

void solve(){
    string s;
    cin >> s;

    int l = 0, r = 0, n = sz(s);
    int ans = 0;
    while(r+1 < n){
        if(s[r] == s[r+1]){
            ans += calc(r - l + 1);
            ans %= MOD;
            l = r+1;
        }        
        r++;
    }
    ans += calc(r - l + 1);
    ans %= MOD;
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}