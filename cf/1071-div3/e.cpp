#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define int long long

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
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int tot = 0;
    for(int i = 0; i < n; i++) tot += p[i];

    if(x + y < tot){
        cout << "NO" << endl;
        return;
    }

    int na = 0, nb = 0, wa = 0, wb = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') na += p[i] / 2 + 1, wa ++;
        else nb += p[i] / 2 + 1, wb ++;
    }

    dbg(x, y, na, nb, x - y, wa, wb);

    if(na > x or nb > y){
        cout << "NO" << endl;
        return;
    }


    if((wa == n and (x - y) < n ) or (wb == n and (y - x) < n)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}