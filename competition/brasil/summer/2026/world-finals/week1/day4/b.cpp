#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

//#define DEBUG

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int MAX = 1e5 + 10;
const int MOD= 998244353;

int fat[MAX];

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> nd, nt, md, mt;

    for(int i = 0; i < n; i++){
        int t;
        char c;
        cin >> t >> c;

        if(c == 'D') nd.push_back(t);
        else nt.push_back(t);
    }

    for(int i = 0; i < m; i++){
        int t;
        char c;
        cin >> t >> c;

        if(c == 'D') md.push_back(t);
        else mt.push_back(t);
    }    

    ll totn = 0, totm = 0;
    for(auto x : nd) totn += x;
    for(auto x : md) totm += x;

    ll ans = mul(fat[sz(nd)], fat[sz(md)]);

    if(totn == totm){
        ans = mul(ans, mul(fat[sz(mt)], fat[sz(nt)]));
    } else if(totn > totm){
        ll diff = totn - totm;
        int cnt = 0;
        for(auto x : mt) if(x > diff) cnt++;
        int x = sz(mt) == 0 ? 1 : mul(cnt, fat[sz(mt) - 1]);
        ans = mul(ans, mul(x, fat[sz(nt)]));
    } else{
        ll diff = totm - totn;
        int cnt = 0;
        for(auto x : nt) if(x > diff) cnt++;
        int x = sz(nt) == 0 ? 1 : mul(cnt, fat[sz(nt) - 1]);
        ans = mul(ans, mul(x, fat[sz(mt)]));
    }

    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    fat[0] = 1;
    for(int i = 1; i < MAX; i++) fat[i] = mul(fat[i-1], i);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}