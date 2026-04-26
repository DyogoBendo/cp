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

const int INF = 1e9 + 10;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++) cin >> v[i];
    
    for(int i = 0; i < m; i++) cin >> b[i];

    int has_odd = 0, has_even = 0;
    for(int i = 0; i < m; i++){
        if((b[i] - 1) & 1) has_odd++;
        else has_even++;
    }

    int mx_odd = -INF;
    int mx_even = -INF;

    vector<int> odds, evens;

    for(int i= 0; i < n; i++){
        if(i & 1){
            mx_odd = max(mx_odd, v[i]);
            odds.push_back(v[i]);
        } else{
            mx_even = max(mx_even, v[i]);
            evens.push_back(v[i]);
        }
    }

    ll tot = 0;
    for(int i = 0; i < n; i++) tot += v[i];
    
    if(has_odd) tot -= mx_odd;
    if(has_even) tot -= mx_even;

    dbg(tot, has_odd, has_even);

    sort(evens.rbegin(), evens.rend());
    sort(odds.rbegin(), odds.rend());
    for(int i = 1; i < min(sz(evens), has_even); i++){
        if(evens[i] > 0) tot -= evens[i];
    }
    for(int i = 1; i < min(sz(odds), has_odd); i++){
        if(odds[i] > 0) tot -= odds[i];
    }

    cout << tot << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}