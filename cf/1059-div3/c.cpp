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

int get_msb(int x){
    return 31 - __builtin_clz(x);
}

void solve(){
    int a, b;
    cin >> a >> b;

    int ka = get_msb(a);
    int kb = get_msb(b);

    if(kb > ka) cout << -1 << endl;
    else{
        vector<int> ans;
        for(int x = 0; x <= ka; x++){
            int xa = (a >> x) & 1;
            int xb = (b >> x) & 1;
            
            if(xa != xb) ans.push_back(1 << x);
        }
        cout << ans.size() << endl;
        for(auto x : ans) cout << x << " ";
        if(sz(ans)) cout << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}