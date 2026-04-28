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

const int INF = 1e9;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    int mn_even = INF, mx_even = 0, mn_odd = INF, mx_odd = 0;

    vector<int> smax_odd(n+1), smax_even(n+1), smin_odd(n+1, INF), smin_even(n+1, INF);

    for(int i = n-1; i >= 0; i--){
        if(v[i] & 1) smax_odd[i] = max(smax_odd[i+1], v[i]), smin_odd[i] = min(smin_odd[i+1], v[i]), mx_odd = max(mx_odd, v[i]), mn_odd = min(mn_odd, v[i]);
        else smax_even[i] = max(smax_even[i+1], v[i]), smin_even[i] = min(smin_even[i+1], v[i]), mx_even = max(mx_even, v[i]), mn_even = min(mn_even, v[i]);
    }

    int pmax_odd = 0, pmax_even = 0, pmin_odd = INF, pmin_even = INF;

    bool possible = true;
    for(int i = 0; i < n; i++){
        if(v[i] & 1) pmax_odd = max(v[i], pmax_odd), pmin_odd = min(pmin_odd, v[i]);
        else pmax_even = max(v[i], pmax_even), pmin_even = min(pmin_even, v[i]);

        if(!i) continue;

        if(v[i] & 1){
            if(pmax_odd > v[i]){
                if(mx_even > pmax_odd or mn_even < v[i]){
                } else possible = false;
            }
        } else{
            if(pmax_even > v[i]){
                dbg(pmax_even, pmax_odd, smax_odd[i], pmin_odd);
                if(mx_odd > pmax_even or mn_odd < v[i]){
                } else possible = false;
            }
        }
    }

    cout << (possible ? "Yes" : "No") << endl;

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}