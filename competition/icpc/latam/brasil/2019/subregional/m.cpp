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

signed main(){
    darvem;

    int n, c, t;
    cin >> n >> c >> t;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    auto check = [&](int x){
        int mx = x*t;
        int cnt= 0;
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(v[i] > mx) return false;
            if(v[i] + cnt > mx){
                if(curr + 1 == c) return false;
                curr++;
                cnt = v[i];
            } else cnt += v[i];
        }
        return true;
    };

    int lo = 0, hi = 1e9 + 10;
    while(lo < hi){
        int m = (hi - lo) / 2 + lo;

        if(check(m)) hi = m;
        else lo = m + 1;
    }
    cout << hi << endl;
}