#include <bits/stdc++.h>
using namespace std;

#define int long long
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



const int MOD = 1e9+7;

signed main(){
    darvem;

    string s;
    int n;
    cin >> s >> n;

    n %= MOD;
    int oc[26] = {0};
    int inv = 0;
    for(int i = 0; i < sz(s); i++){
        int c = s[i] - 'a';        
        for(int j = c+1; j < 26; j++) inv = (inv + oc[j]) % MOD;
        oc[c]++;
    }    

    inv = (inv * n) % MOD;

    int tot = 0;
    for(int i = 0; i < 26; i++){
        int a = (((n ) * (n-1)) % MOD);
        int b = ((MOD+1)/2) % MOD;        
        int p = (1LL * a * b) % MOD;
        dbg(tot, a, b, p);
        inv =  (inv + ((1LL * oc[i] % MOD) * tot % MOD) * p % MOD) % MOD;

        dbg(tot, oc[i]);
        tot += oc[i];
    }

    cout << inv << endl;
}