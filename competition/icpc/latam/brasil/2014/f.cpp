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

#define int long long

const int MOD = 1e4;
int n, l, s, t;
typedef vector<vector<int>> M;

M mul(M m1, M m2){
    M ans(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ans[i][j] += (m1[i][k]*m2[k][j]) % MOD;
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

M fast_expo(M g, int x){
    M ans(n, vector<int>(n));
    for(int i = 0; i < n; i++) ans[i][i] = 1;

    while(x){
        if(x & 1){
            ans = mul(ans, g);
        }

        g = mul(g, g);
        x>>=1;
    }
    return ans;
}

signed main(){
    darvem;

    cin >> n >> l >> s >> t;

    s--;t--;
    M g(n, vector<int>(n));

    for(int i = 0; i < n; i++){        
        for(int j = 0; j < 4; j++){
            int x;
            cin >> x;
            g[i][x-1]++;
        }                
    }

    M ans = fast_expo(g, l);
    cout << ans[s][t] << endl;
}