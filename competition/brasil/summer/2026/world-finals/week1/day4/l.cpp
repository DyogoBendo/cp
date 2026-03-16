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

const int C = 5;

int calc_lim_inf(int i){
    int x = i/9 - C*sqrt(i);
    dbg("inf", i, x);
    return max(x, 0);
}

int calc_lim_sup(int i){
    int x = i/9 + C*sqrt(i); 
    dbg("sup", i, x);
    return min(x, i);
}

const int MAXN = 4e5 + 10;

ll dp[MAXN], dp2[MAXN];

signed main(){
    darvem;
    int n;
    cin >> n;

    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];    
    
    dbg(n);
    ll ans = 0;
        
    for(int i = 1; i <= n; i++){
        int inf = calc_lim_inf(i);
        int sup = calc_lim_sup(i);        
        for(int j = inf; j < sup; j++){
            dp2[j] = max(dp[j] + a[i]*b[i-j], (j > 0 ? dp[j-1] : 0));
            ans = max(ans, dp2[j]);
        }        
        for(int j = inf; j < sup; j++) dp[j] = dp2[j];
    }
    cout << ans << endl;
}