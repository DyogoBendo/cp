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

const int MOD = 1e9+7;

signed main(){
    darvem;

    int n;
    string s;
    cin >> n >> s;

    // 0 sempre é valido, porque ele é neutro na soma, or e xor
    // todos os 0 podem ser 1

    ll tot = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') tot = (tot *2) % MOD;
    }
    cout << tot-1 << endl;
}