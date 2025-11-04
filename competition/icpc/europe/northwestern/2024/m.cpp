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

pair<double, double> mul(int x, pair<double, double> p){
    return make_pair(p.first*x, p.second*x);
}

double cross(pair<double, double> l, pair<double, double> r){
    return (l.first*r.second - l.second*r.first);
}

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(int i=0; i < n; i++) cin >> v[i].first >> v[i].second;

    vector<pair<double, double>> psum(n+1);
    vector<pair<double, double>> ssum(n+1);
    for(int i =0; i < n; i++){
        psum[i+1] = make_pair(psum[i].first + v[i].first, psum[i].second + v[i].second);
        ssum[n-i-1] = make_pair(ssum[n-i].first + v[n-i-1].first, ssum[n-i].second + v[n-i-1].second);
    }

    double polygon_area=0;
    for(int i = 0; i < n; i++){
        int j = (i+1) % n;        
        polygon_area += cross(v[i], v[j]);
    }

    double sarea = 0;
    for(int i = 1; i < n - 1; i++){        
        auto m1 = mul(i, v[i]);        
        pair<double, double> l = make_pair(m1.first - psum[i].first, m1.second - psum[i].second);

        auto m2 = mul(n-i-1, v[i]);        
        pair<double, double> r = make_pair(ssum[i+1].first - m2.first, ssum[i+1].second - m2.second);
        sarea += cross(l, r);
    }    

    double ans = sarea / polygon_area;

    cout << fixed << setprecision(12) << ans << endl;
}