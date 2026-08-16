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

#define int ll

pair<int, int> r;

ld d(pair<int, int> p, pair<int, int> q){        
    int dx = p.first - q.first;
    int dy = p.second - q.second;
    return sqrtl(dx*dx+ dy*dy);
}

ld dist(pair<int, int> p){
    return d(p, r);
}

bool comp(pair<int, int> p, pair<int, int> q){
    return dist(p) < dist(q);
}

signed main(){
    darvem;

    int n;
    cin >> n;
    vector<pair<int, int>> pts(n);
    for(int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;

    r = pts[0];
    sort(pts.begin(), pts.end(), comp);    

    r = pts.back();    
    sort(pts.begin(), pts.end(), comp);    

    ld ans = 0;
    for(int i = 1; i < n; i++) ans += d(pts[i-1], pts[i]);

    cout << setprecision(15) << fixed << ans << endl;
}