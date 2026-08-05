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

bool get_digits_xor(ll x, int b){
    int ans = 0;
    while(x){
        ans ^= x % b;
        x /= b;
    }
    return ans == 0;
}

bool check_divisor(ll x, ll d){
    ll b = (x/d) - 1;
    return (b > d);
}

signed main(){
    darvem;

    ll x;
    cin >> x;

    ll ans = 0;
    for(ll i = 1; i*i <= x; i++){
        if(x % i == 0){
            ans += check_divisor(x, i);
            if(x/i != i) ans += check_divisor(x, x/i);
        }
    }

    for(ll i = 2; i * i <= x; i++) ans += get_digits_xor(x, i);
    
    cout << ans << endl;
}