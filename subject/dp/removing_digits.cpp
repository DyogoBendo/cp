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

const int MAXN = 1e6 + 10;
const int INF = 1e9;

signed main(){
    darvem;

    int dp[MAXN];
    fill(dp, dp + MAXN, INF);

    dp[0] = 0;
    for(int i = 1; i < MAXN; i++){
        int x = i;
        
        while(x){
            dp[i] = min(dp[i], dp[i - x%10] + 1);
            x/=10;
        }
    }

    int n;
    cin >> n;
    cout << dp[n] << endl;
}