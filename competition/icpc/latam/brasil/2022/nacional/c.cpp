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

ll has_bit_active(ll x, ll pos){
    return (x >> pos) & 1LL;
}

signed main(){
    darvem;

    ll n, p, h;
    cin >> n >> p >> h;

    p--; h--;

    ll move_sequence = 0;

    ll inv = 0;
    for(ll i = n - 1; i >= 0; i--){
        ll add = (has_bit_active(h, i) ^ inv);
        move_sequence |= add << i;
        inv ^= add;
    }

    inv = 0;
    for(ll i = n-1; i >= 0; i--){
        ll flip = (has_bit_active(move_sequence, n - 1 - i));               
        inv ^= flip;        
        ll pos = (has_bit_active(p, i) ^ inv);
        cout << (pos? "L" : "R");
    }
    cout << endl;

}