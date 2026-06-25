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

void solve(){
    int a, b, x;
    cin >> a >> b >> x;

    int bst = 2e9;

    int cnt = 0;
    while(a != b){
        if(a > b) swap(a, b);

        bst = min(bst, cnt + b - a);
        cnt++;
        b /= x;
    }
    bst = min(bst, cnt);
    cout << bst << endl;
}   


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}