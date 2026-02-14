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
    int h, w, n;
    cin >> h >> w >> n;
    
    set<tuple<int, int, int>> xorder, yorder;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        xorder.insert({-x, -y, i});
        yorder.insert({-y, -x, i});
    } 

    vector<pair<int, int>> ans(n);

    int l = 1, b = 1;
    for(int i = 0; i < n; i++){
        auto [ax, ay, ai] = *xorder.begin();
        auto [by, bx, bi] = *yorder.begin();

        
        ax = -ax;
        ay = -ay;
        
        bx = -bx;
        by = -by;
        dbg(ax, ay, ai, bx, by, bi, l, b, w, h);        

        if(ax == h){    
            ans[ai] = {l, b};
            xorder.erase({-ax, -ay, ai});
            yorder.erase({-ay, -ax, ai});
            w -= ay;
            b += ay;
        } else{
            ans[bi] = {l, b};
            xorder.erase({-bx, -by, bi});
            yorder.erase({-by, -bx, bi});
            h -= bx;
            l += bx;
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i].first << " " << ans[i].second << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}