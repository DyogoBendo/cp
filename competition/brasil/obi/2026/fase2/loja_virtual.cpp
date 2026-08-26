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

const int MAXN = 803;
int grid[MAXN][MAXN], suf[MAXN][MAXN], H[MAXN][MAXN];
pair<int, int> st[MAXN];
int pos_st = 0;

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> grid[i][j];

        grid[i][m] = -1e9;
        suf[i][m] = 0;

        for(int j = m-1; j >= 0; j--) suf[i][j] = (grid[i][j+1] > grid[i][j] ? suf[i][j+1] : 0) + 1;
    } 

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int x = lower_bound(grid[i] + j, grid[i] + j + suf[i][j], grid[i+1][j]) - (grid[i] + j);            
            H[i][j] = min(suf[i+1][j], x);
        }
    }
    
    ll ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, (ll)suf[i][j]);
        }
    }
    
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){                                    
            int cur = (i == n - 1) ? 0 : H[i][j];
            int l = i;
            while(pos_st > 0 and st[pos_st].first >= cur){
                ans = max(ans, 1LL * (i - st[pos_st].second + 1) * st[pos_st].first);
                l = st[pos_st].second;
                pos_st--;
            }
            st[++pos_st] = {cur, l};            
        }
        while(pos_st > 0){
            ans = max(ans, 1LL * (n - st[pos_st].second) * st[pos_st].first);
            pos_st--;
        }
    }
    cout << ans << endl;
}