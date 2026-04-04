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

const int MOD = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<ll> va(n+1), vb(m+1);

    for(int i = 1; i <= n; i++) cin >> va[i];
    for(int j = 1; j <= m; j++) cin >> vb[j];

    vector<ll> ssum(m+2);
    for(int i = m; i> 0; i--){
        ssum[i] = (ssum[i+1] + vb[i]) % MOD;
    }

    ll pref = 0;
    ll ans = 0;
    ll curr = 0;
    for(int i = 1; i <= n; i++){
        if(i <= m){
            ll add_suf = (((va[i]* i) % MOD) *ssum[i+1]) % MOD;        
            dbg(i, va[i], ssum[i+1], add_suf);
            ans += add_suf;
        }         
        curr += pref;        
        dbg(pref, curr);
        for(int x = 1; x*x <= i and x <= m; x++){
            if(i % x != 0) continue;
            if(i == x) continue;
            dbg(x, vb[x]);
            curr = (curr + MOD - ((x * vb[x]) % MOD)) % MOD;                                
            int d = i/x;
            if(d != x and d != i and d <= m){
                dbg(d, vb[d]);
                curr = (curr + MOD - ((d * vb[d]) % MOD)) % MOD;                    
            }
        }
        
        if(i <= m) pref = (pref + vb[i]) % MOD;
        dbg(curr);
        ans = (ans + (curr * va[i] % MOD)) % MOD;
        
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}