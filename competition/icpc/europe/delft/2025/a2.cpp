#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) a.size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int genL(int a, int l){
    return (int) ceil(((double)l-a) / 12.0);
}

int genR(int a, int r){
    return (int) floor(((double)r-a) / 12.0);
}

int INF = 1e9;

void solution(){
    int n,l,r;
    cin >> n >> l >> r;

    vector<int> notes(n), low(n+1), high(n+1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        low[i+1] = genL(x, l);
        high[i+1] = genR(x, r);
    }

    vector<int> dp(n+1);
    dp[0] = INF;
    
    for (int i = 1; i <= n; i++)
    {   
        int L = -INF, R = INF;
        for (int j = i; j >= 1; j--)
        {
            L = max(L, low[j]);
            R = min(R, high[j]);

            if(L > R) break;

            dp[i] = max(dp[i], min({dp[j-1], i-j+1}));
        }
    }
    
    cout << dp[n] << endl;
}

signed main(){
    int cases = 1;

    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    
}