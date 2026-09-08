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

void test(int x){
    for(int i = 0; i <= x/2; i++){
        dbg(i, x - i, (x-i) ^ i);
    }
}

void solve(){
    int x, y;
    cin >> x >> y;

    int s = (x + y);

    int b = 31 - __builtin_clz(s);
    int cx = 0;
    for(int i = b; i >= 0; i--){
        if((s >> i) & 1){
            if(cx + (1 << i) <= x) cx += (1 << i);
        }
    }

    cout << s << " " << x - cx << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}