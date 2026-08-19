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

const int MOD = 1e9 + 7;
const int MAXK = 51;

map<vector<int>, int> dp[MAXK];

signed main(){
    darvem;

    int n, k, t;
    cin >> n >> k >> t;

    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    dp[0][v] = 1;

    for(int i = 0; i < k; i++){
        for(auto [u, x] : dp[i]){
            vector<int> tmp = u;                        
            for(int a = 0; a < n; a++) for(int b = a + 1; b < n; b++){
                swap(tmp[a], tmp[b]);
                dp[i+1][tmp] = (dp[i+1][tmp] + x) % MOD;
                swap(tmp[a], tmp[b]);
            }
        }
    }

    while(t--){
        for(int i = 0; i < n; i++) cin >> v[i];

        cout << dp[k][v] << endl;
    }
}