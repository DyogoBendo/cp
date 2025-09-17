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

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;    
    ll tot = 0, l = 1, r = 1e18;        
    for(int i = 0; i < n-1; i++){
        ll d = abs((v[i].first == v[i+1].first ? v[i].second - v[i+1].second : v[i].first - v[i+1].first));
        tot += d;        
        if(i&1) l = max(l, -tot + 1);
        else r = min(r, tot - 1);
        dbg(tot, l, r);
        tot = -tot;
    }

    if(l > r) cout << -1 << endl;
    else cout << r << endl;
}