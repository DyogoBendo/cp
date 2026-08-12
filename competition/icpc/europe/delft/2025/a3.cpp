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

signed main(){
    darvem;

    int n, l, h;
    cin >> n >> l >> h;

    vector<int> v(n+1), va(n+1), vb(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        va[i] = (l - v[i]) / 12;
        if(l > v[i] and (l - v[i]) % 12) va[i]++;
    }

    for(int i = 1; i <= n; i++){
        vb[i] = (h - v[i]) / 12;
        if(h < v[i] and (v[i]-h) % 12) vb[i]--;
    } 

    vector<int> dp(n+1);

    dp[0] = 1e9;
    for(int i = 1; i <= n; i++){
        int a = va[i];
        int b = vb[i];
        for(int j = i; j > 0; j--){
            a = max(a, va[j]);
            b = min(b, vb[j]);
            if(a > b) break;

            dp[i] = max(dp[i], min(dp[j-1], i-j+1));
        } 
    }
    cout << dp.back() << endl;
}