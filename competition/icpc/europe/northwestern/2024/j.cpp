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

    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
        int x, y, h;
        cin >> x >> y >> h;
        v.push_back({x, y, h});
    }

    for(int i = 0; i < n; i++){
        auto [xi, yi, hi] = v[i];        
        int bst = hi*hi;
        for(int j = 0; j < n; j++) if(i != j){
            auto [xj, yj, hj] = v[j];                    
            if(hj > hi){
                int dx = xi - xj;
                int dy = yi - yj;

                bst = min(bst, (dx*dx + dy*dy));
            }
        }                
        int ans = 1;
        for(int k = 1; k * k <= bst; k++) ans = k;        
        cout << ans << endl;
    }
}