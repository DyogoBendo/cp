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

    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(n));    

    for(int i = 0; i < n; i++) cin >> v[i];

    for(int tam = 2; tam <= n; tam++){
        for(int i = 0; i <= n - tam; i++){
            int j = i + tam - 1;

            vector<int> in_range;
            vector<int> pos(n+1);
            for(int k = 0; k < n; k++) if(v[k] >= i and v[k] <= j) pos[v[k]] = sz(in_range), in_range.push_back(v[k]);

            vector<int> diff(n+1);
            
            for(int k = 0; k < sz(in_range) - 1; k++){                
                int mn = min(in_range[k], in_range[k+1]);
                int mx = max(in_range[k], in_range[k+1]);

                if(mn+1 < mx){
                    diff[mn+1]++;
                    diff[mx]--;
                }
            }
            int curr = 0;
            for(int k = 0; k < n; k++){
                curr += diff[k];
                diff[k] = curr;
            } 
            
            for(int k = i; k <= j; k++){
                int cnt = diff[k];
                int p = pos[k];

                if(p > 0 and p < sz(in_range) - 1){
                    int mn = min(in_range[p-1], in_range[p+1]);
                    int mx = max(in_range[p-1], in_range[p+1]);                    
                    if(mn < k and mx > k) cnt++;
                }

                int l = k > i ? dp[i][k-1] : 0;
                int r = k < j ? dp[k + 1][j] : 0;
                dp[i][j] = max(dp[i][j], l + r + cnt);
            }            
        }
    }

    cout << dp[0][n-1] << endl;
}