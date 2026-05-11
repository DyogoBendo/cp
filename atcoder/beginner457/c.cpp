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

#define int ll

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        v[i] = vector<int>(l);
        for(int j = 0; j < l; j++) cin >> v[i][j];
    }

    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    ll cnt = 0;
    for(int i = 0; i < n; i++){
        ll l = sz(v[i]);
        dbg(cnt, l, c[i], l*c[i]);        
        if(l*c[i] + cnt >= k){
            ll rem = (k - cnt - 1 + l) % l;                                  
            cout << v[i][rem] << endl;
            return;

        } else cnt += l*c[i];
    }
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}