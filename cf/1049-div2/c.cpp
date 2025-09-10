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
    vector<ll> v(n), v2;
    ll tot = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i%2 == 0) tot += v[i];
        else tot -= v[i];
    } 
    v2 = v;


    ll left = 0;
    ll right = 0;
    int curr =0;

    set<pair<ll, int>> s;
    for(int i = 0; i < n; i ++){
        v[i] += curr;
        if(i % 2) v[i] *= -1;
        s.insert({v[i], i});
        curr ++; 
    }

    curr = 0;
    ll ans = 0;
    for(int i = 0; i < n; i ++){
        int x = v2[i];
        if(i%2) x *= -1;
        left = max(left, v2[i] - curr);
        s.erase({-v[i], i});
        if(s.size()) right = -(s.begin()->first);

        dbg(i, left, right);
        ans = max({ans, i + left - v2[i], right - i - v2[i]});
        
    }
    cout << tot + ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}