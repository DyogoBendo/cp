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

    vector<tuple<double, double, double>> v(n);
    for(auto &[r, x, y] : v) cin >> x >> y >> r;

    sort(v.begin(), v.end());    

    dbg(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double r = get<0>(v[j]) - get<0>(v[i]);
            double dx = get<1>(v[j]) - get<1>(v[i]);            
            double dy = get<2>(v[j]) - get<2>(v[i]);                        

            if(r > 100 or ans > 2*n) break;            

            if(dx*dx + dy*dy > r*r) ans += 2;
        }
    }

    if(ans > 2*n) cout << "greater" << endl;
    else cout << ans << endl;
}