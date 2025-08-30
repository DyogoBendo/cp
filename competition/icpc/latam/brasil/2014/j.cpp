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

double dist(pair<double, double> p, pair<double, double> q){
    return hypot(p.first - q.first, p.second - q.second);
}

signed main(){
    darvem;

    int n;
    cin >> n;

    n *= 2;
    vector<pair<double, double>> pts(n);
    for(int i = 0; i < n; i++){
        cin >> pts[i].first >> pts[i].second;
    }

    vector<vector<double>> dp(n, vector<double>(n, 1e9));
    vector<vector<double>> d(n, vector<double>(n));
    for(int i = 0; i < n; i++){
        for(int j = i + 2; j < n; j++) d[i][j] = dist(pts[i], pts[j]);
    }

    function<double(int, int)> calc = [&](int l, int r){
        if(dp[l][r] != 1e9) return dp[l][r];
        if(r - l + 1 <= 4) return dp[l][r] = 0.0;

        for(int i = l + 1; i < r; i += 2){
            for(int k = i + 1; k < r; k+= 2){
                dp[l][r] = min(dp[l][r], calc(l, i) + calc(i, k) + calc(k, r) + d[l][i] + d[i][k] + d[k][r]);
            }
        }
        return dp[l][r];
    };

    cout << fixed << setprecision(4) << calc(0, n-1) << endl;
}