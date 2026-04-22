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

const ld PI = acos(-1);
const ld eps = 1e-9;

signed main(){
    darvem;

    int n;
    ld h;
    cin >> n >> h;

    vector<tuple<ld, ld, ld>> v(n);
    for(int i = 0; i < n; i++){
        ld x, y, z;
        cin >> x >> y >> z;
        v[i] = {z, x, y};
    }

    ld a, b;
    cin >> a >> b;

    sort(v.rbegin(), v.rend());

    auto check = [&](int tam){
        vector<ld> angles;
        for(int i = 0; i < tam; i++){
            auto [z, x, y] = v[i];
            x -= a;
            y -= b;
            if(abs(x) > eps or abs(y) > eps) angles.push_back(atan2(y, x));
        }
        if(!sz(angles)) return false;
        sort(angles.begin(), angles.end());

        vector<ld> A(2*sz(angles));
        for(int i = 0; i < sz(angles); i++) A[i] = angles[i], A[i+sz(angles)] = angles[i] + 2.0*PI;        

        int j = 0, k = 0;
        for(int i = 0; i < sz(angles); i++){            
            while(j + 1 < i + sz(angles) && A[j + 1] - A[i] < PI - eps) j++;                        

            if(k < j) k = j;                        
            while(k + 1 < i + sz(angles) && A[k + 1] - A[j] < PI - eps) k++;                        

            if(j > i && k > j && A[i + sz(angles)] - A[k] < PI - eps) return true;             
        }
        return false;
    };

    int lo = 0, hi = n+1;
    while(lo < hi){
        int m = (hi - lo) / 2 + lo;

        if(check(m)) hi = m;
        else lo = m + 1;        
    }
    
    if(hi== n+1) cout << -1 << endl;
    else cout << fixed << setprecision(12) << max((ld) 0, h - get<0>(v[hi-1])) << endl;
}