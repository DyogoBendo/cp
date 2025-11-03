#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

ll expo(ll x, ll k, ll mod){
    ll ans = 1;
    while(k){
        if(k & 1){
            ans =(ans * x) % mod;
        }
        x = (x * x) % mod;
        k >>= 1;
    }
    return ans;
}

void solution(){
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string ans = s;
    s += s;

    ll p = expo(2, k, n);

    for(int i = 0; i < n; i++){
        ll curr = (i*p) % n;
        ans[i] = s[curr];
    }

    cout << ans << endl;
}

signed main(){
    int cases = 1;
    // cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
    
}