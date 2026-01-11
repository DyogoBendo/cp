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
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    while(q--){
        int x, y;
        cin >> x >> y;

        int lo = 0;
        int hi = n+1;

        int prev = lower_bound(v.begin(), v.end(), x) - v.begin();
        dbg(x, y, prev);
        while(lo < hi){
            int m = (hi - lo) / 2 + lo;
            
            int tot = lower_bound(v.begin(), v.end(), x+ y + m) - v.begin();

            dbg(m, y+m+x-1, tot, tot-prev);
            
            if(tot-prev <= m){
                hi = m;
            } else{
                lo = m + 1;
            }
        }
        dbg(lo);
        cout << x+lo-1+y << endl;
    }
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}