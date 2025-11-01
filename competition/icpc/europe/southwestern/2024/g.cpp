#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    ll r, n;
    cin >> r >> n;

    ll a = 0, b = r;

    for(int i = 0; i < n; i++){
        ll d;
        cin >> d;

        a = max(min(r, a + d), 0ll);
        b = max(min(r, b + d), 0LL);
        dbg(a, b);
    }

    if(a == b) cout << a << endl;
    else cout << "uncertain" << endl;

}

signed main(){
    fastio;
    int n=1;
    //cin >> n;
    for (int i=0; i<n; i++){
        solution();
    }
}