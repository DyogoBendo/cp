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

const int MAXN=  5e5 + 10;

int ap[MAXN], v[MAXN], dp[MAXN];

int calc(int l, int r, int x){
    if(dp[x] != -1) return dp[x];
    if(r < l or !x) return 0;
    int pos = ap[x];
    if(pos < l or pos > r) return dp[x] = calc(l, r, x-1);

    if(pos == l) l++;
    else if(pos == r) r--;
    else if(v[pos-1] < v[pos] and v[pos+1] < v[pos]){
        int dl = pos - l;
        int dr = r - pos;
        
        return dp[x]= min(dl + calc(pos+1, r, x-1), dr + calc(l, pos-1, x-1));
    }
    return dp[x] = calc(l, r, x-1);
}

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) ap[v[i]] = i;

    for(int i = 0; i<= n; i++) dp[i] = -1;

    int l = 1, r = n;

    cout << calc(l, r, n) << endl;
}   


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}