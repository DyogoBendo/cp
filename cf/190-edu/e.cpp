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

const int MAX = 2e6 + 10;
const int INF = 2e9 + 10;

int min_p[MAX], min_c[MAX];
int min_p_pre[MAX], min_c_pre[MAX];
int min_p_suf[MAX], min_c_suf[MAX];


void solve(){
    int n, m;
    cin >> n;

    for(int i = 0;i < MAX; i++) min_p[i] = min_c[i] = min_p_pre[i] =  min_p_suf[i] =  min_c_suf[i] = min_c_pre[i] = INF;

    vector<int> p(n+1), c(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];    

    for(int i = 1; i <= n; i++) min_c[p[i]] = min(min_c[p[i]], c[i]);
    for(int i = 1; i <= n; i++) min_p[c[i]] = min(min_p[c[i]], p[i]);

    min_p_pre[0] = min_p[0];
    min_c_pre[0] = min_c[0];
    for(int i = 1; i < MAX; i++){
        min_p_pre[i] = min(min_p_pre[i-1] , min_p[i]);
        min_c_pre[i] = min(min_c_pre[i-1] , min_c[i]);
    }

    min_p_suf[MAX-1] = min_p[MAX-1];
    min_c_suf[MAX-1] = min_c[MAX-1];
    for(int i = MAX-2; i > 0; i--){
        min_p_suf[i] = min(min_p_suf[i+1], min_p[i]);
        min_c_suf[i] = min(min_c_suf[i+1], min_c[i]);
    }

    int mn = INF;
    for(int i = 1; i <= n; i++){
        mn = min(mn, p[i] + c[i]);
    }

    cin >> m;
    vector<int> tp(m), tc(m), d(m);
    for(int i = 0; i < m; i++) cin >> tp[i];
    for(int i = 0; i < m; i++) cin >> tc[i];
    for(int i = 0; i < m; i++) cin >> d[i];


    for(int i = 0; i < m; i++){
        int x = tp[i];
        int y = tc[i];
        
        int xd = x + d[i];
        int yd = y + d[i];
        int less_then_p =  x ? min_c_pre[x-1] : INF;
        if(less_then_p < y) less_then_p = 0;
        if(less_then_p > yd and less_then_p != INF) less_then_p = yd;

        int less_then_c = y ? min_p_pre[y-1] : INF;
        if(less_then_c < x) less_then_c = 0;
        if(less_then_c > xd and less_then_c != INF) less_then_c = xd;

        
        int greater_then_pd = min_c_suf[xd];
        if(greater_then_pd < y) greater_then_pd = 0;
        if(greater_then_pd > yd and greater_then_pd != INF) greater_then_pd = yd;
        greater_then_pd += xd;

        int greater_then_cd = min_p_suf[yd];
        if(greater_then_cd < x) greater_then_cd = 0;
        if(greater_then_cd > xd and greater_then_cd != INF) greater_then_cd = xd;
        greater_then_cd += yd;

        dbg(x, y, xd, yd, mn, less_then_p, less_then_c, greater_then_pd, greater_then_cd);
        cout << min({mn, less_then_p, less_then_c, greater_then_pd, greater_then_cd}) << endl;
    }

}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}