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

const int MOD=  998244353;

int fast_expo(int x, int k){
    int res = 1;
    while(k){
        if(k & 1){
            res = (1LL * res * x) % MOD;
        }
        x = 1LL*x*x%MOD;
        k >>= 1;
    }
    return res;
}

int inv(int x){
    return fast_expo(x, MOD-2);
}

int divide(int x, int y){
    return 1LL*x*inv(y) % MOD;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.rbegin(), v.rend());

    int tot = 1;
    for(int i = 1; i < n; i++) tot = (1LL * tot * i) % MOD;

    int sum = 0;
    for(int i = 1; i < n; i++) sum = (sum - v[i] + MOD) % MOD;    

    int ans = 1LL * tot * sum % MOD;

    int sum2 = v[0];        
    for(int i = 1; i < n; i++){        
        int d = divide(tot, i);
        int add = (1LL * sum2 * d) % MOD;                
        ans = (ans + add) % MOD;
        sum2 = (sum2 + v[i]) % MOD;
    }       
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}

