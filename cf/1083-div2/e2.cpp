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

const int MOD = 998244353;

#include <bits/stdc++.h>
#define fr1(i, a, b) for (int i = a; i <= b; i++)
#define fr2(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
const int N = 1e5 + 10;
const int mod = 998244353;
int tc;
int n;
int a[N];
int dp[N];
int kmp[N];
void add(int & x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
void solve() {
    cin >> n;
    fr1(i, 1, n) cin >> a[i];
    dp[0] = 1;
    fr1(i, 1, n) dp[i] = 0;
    fr1(i, 1, n) {
        kmp[i] = i + 1;
        int poi = i + 1;
        fr2(j, i - 1, 1) {
            dbg(i, j, poi);
            while (a[j] != a[poi - 1] && poi != i + 1) poi = kmp[poi];
            dbg(i, j, poi);
            if (a[j] == a[poi - 1]) poi--;
            kmp[j] = poi;
        }
        fr2(j, i, 1) {
            if (kmp[j] == i + 1) add(dp[i], dp[j - 1]);
        }
        dbg(i, dp[i]);
    }    
    cout << dp[n] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin >> tc;
    while (tc--) solve();
}