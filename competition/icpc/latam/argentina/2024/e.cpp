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

const int N = 200 + 1;
const int P = 1e5 + 1;

signed main(){
    darvem;

    int n, p;
    cin >> n >> p;

    vector<tuple<int, int, int>> v(n);
    for(auto &[a, b, c] : v) cin >> a >> b >> c;

    sort(v.begin(), v.end(), [](const tuple<int, int, int>& w1, const tuple<int, int, int>& w2) {
        auto [a1, b1, c1] = w1;
        auto [a2, b2, c2] = w2;        
        return b1 + 1LL * b2 * a1 < b2 + 1LL * b1 * a2;
    });

    vector<int> dp(P, -1);
    dp[p] = 0;

    int ans = 0;

    for(int j = 0; j < n; j++){
        auto [a, b, c] = v[j];
        for(int i = b; i < P; i++){
            if(dp[i] == -1) continue;
            int x = (i - b) / a;
            dbg(i, a, b, c, x);
            if(x >= 0) dp[x] = max(dp[x], dp[i] + c), ans = max(ans, dp[x]);
        }
    }
    cout << ans << endl;    
}