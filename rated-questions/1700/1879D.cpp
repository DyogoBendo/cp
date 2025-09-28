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

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    for(int i = 0; i < 32; i++){
        ll p[2] = {0, 0}, cnt[2] = {1, 0};
        ll curr = 0, b = 0;        
        for(ll j = 0; j < n; j++){
            int x = (v[j] >> i) & 1;
            b ^= x;
        
            curr = (curr + ((j + 1) * cnt[!b]) - p[!b] + MOD ) % MOD;            

            cnt[b]++; 
            p[b]=(p[b]+j+1) % MOD;
        }        
        ans = (ans + (curr << i)) % MOD;
    }    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}