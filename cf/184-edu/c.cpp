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
    int n;
    cin >> n;

    vector<ll> v(n+1);
    vector<ll> psum(n+1);

    ll tot = 0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        tot += v[i];
        psum[i] = psum[i-1] + v[i];
    }
    
    ll curr = 0;
    ll mx =0;
    vector<pair<ll, ll>> bst;
    for(ll i = 1; i <= n; i++){
        curr += v[i];
        ll x = (i) * (i+1) - curr;
        bst.push_back({x, i});
        mx = max(mx, x);
    }
    sort(bst.rbegin(), bst.rend());
    int l = 0;
    for(ll i = 2; i <= n; i++){
        while(l < n and bst[l].second < i) l++;
        ll pos = bst[l].second;
        ll x = (i + pos) * (pos-i+1) - (psum[pos] - psum[i-1]);
        mx = max(mx, x);
    }
    cout << tot + mx << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}