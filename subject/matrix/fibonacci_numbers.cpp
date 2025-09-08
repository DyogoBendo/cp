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

typedef vector<vector<ll>> M;

const int MOD = 1e9+7;

M mul(M a, M b){
    M tmp = {{0, 0}, {0, 0}};
    for(int i = 0; i < sz(a); i++){
        for(int j = 0; j < sz(b); j++){
            for(int k = 0; k < sz(a); k++){
                tmp[i][j] += a[i][k] * b[k][j] % MOD;
                tmp[i][j] %= MOD;
            }
        }
    }
    return tmp;
}

M expo(M b, ll k){
    M ans = {{1, 0}, {0, 1}};

    while(k){
        if(k & 1) ans = mul(b, ans);
        b = mul(b, b); 
        k >>= 1;
    }
    return ans;
}

signed main(){
    darvem;

    ll n;
    cin >> n;

    M m = {{0, 1}, {1, 1}};

    M p = expo(m, n);

    cout << p[0][1] << endl;

}