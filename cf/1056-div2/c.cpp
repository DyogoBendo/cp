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
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i] --;
    } 

    function<bool(int, int, int)> calc = [&](int l, int r, int idx){
        if(idx == n) return r == 0;
        int need_right = v[idx] - l;
        if(need_right < 0) return false;
        if(need_right + idx > n) return false;
        
        if(need_right == r){
            return calc(l + 1, r, idx+1);
        } else if(need_right == r - 1){
            return calc(l, r-1, idx+1);
        }

        return false;
    };

    int ans = 0;
    int l = calc(1, v[0], 1);
    int r = calc(0, v[0], 1);     
    ans = l + r;    

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}