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

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.rbegin(), v.rend());

    map<int, ll> mp;

    for(int i = 0; i < n; i++) mp[v[i]] += v[i];

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += v[i];

    vector<ll> v2;
    for(auto [x, y] : mp){
        v2.push_back(y);
    }

    sort(v2.rbegin(), v2.rend());

    for(int i = 0; i < min(k, sz(v2)); i++) ans -= v2[i];

    cout << ans << endl;
}