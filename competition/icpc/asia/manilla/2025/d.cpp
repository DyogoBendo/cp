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

pair<int, int> get_frac(int a, int b){
    int g = gcd(a, b);
    return make_pair(a/g, b/g);
}

double calc(vector<pair<double, double>> v){
    double ans = 0;
    double curr_vol = 0, curr_alc = 0;
    for(int i = 0; i < sz(v); i++){
        double prev=  curr_vol;
        curr_vol += v[i].second;
        if (prev == 0) ans += v[i].first * v[i].second;
        else ans += v[i].first * ( curr_vol - prev) + (curr_alc - v[i].first*prev) * log(curr_vol/prev);

        curr_alc += v[i].first*v[i].second;
    }
    return ans;
}


signed main(){
    darvem;

    int n;
    cin >> n;


    vector<int> v(n), a(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> a[i];

    double tot = 0;
    map<pair<int, int>, ll> mp;
    for(int i = 0; i < n; i++){
        mp[get_frac(a[i], v[i])] += v[i];
        tot += v[i];
    }    

    vector<pair<double, double>> d;
    for(auto [x, y] : mp){
        d.push_back({1.0 * x.first / (x.second * 1.0), y});
    }
    sort(d.rbegin(), d.rend());

    double area = calc(d);
    reverse(d.begin(), d.end());
    area -= calc(d);

    cout << fixed << setprecision(14) << area/tot << endl;
}