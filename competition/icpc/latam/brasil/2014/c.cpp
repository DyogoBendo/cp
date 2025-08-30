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

int dot(int x, int y, int z, int a, int b, int c){
    return x*a + y*b + z*c;
}

signed main(){
    darvem;

    int m, n;
    cin >> m >> n;

    vector<tuple<int, int, int, int>> planes(m);
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        planes[i] = {a, b, c, d};
    }

    map<string, int> mp;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;

        string s;
        for(int j = 0; j < m; j++){
            auto [a, b, c, d] = planes[j];

            if(a*x + b*y + c*z < d) s += '1';
            else s += '0';
        }
        ans= max(ans, ++mp[s]);
    }

    cout << ans << endl;

}