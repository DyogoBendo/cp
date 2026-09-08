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

void solve() {
    int r, c;
    cin >> r >> c;
    
    int R = 2 * r - 1;
    int C = 2 * c - 1;
    vector<string> grid(R);
    for (int i = 0; i < R; i++) cin >> grid[i];    
    
    int R_min = 0, R_max = R - 1;
    int C_min = 0, C_max = C - 1;
    
    bool changed = true;
    while (changed) {
        changed = false;            
        for (int i = R_min + 1; i < R_max; i += 2) {
            bool valid = true;                        
            char first_fold = grid[i][C_min];
            for (int c_idx = C_min; c_idx <= C_max; c_idx += 2) {
                if (grid[i][c_idx] != first_fold) {
                    valid = false;
                    break;
                }
            }
            
            if (!valid) continue;
                        
            int D = min(i - R_min, R_max - i);
            for (int d = 1; d <= D; d++) {
                if (d % 2 != 0) {                    
                    for (int c_idx = C_min + 1; c_idx <= C_max - 1; c_idx += 2) {
                        if (grid[i - d][c_idx] == grid[i + d][c_idx]) {
                            valid = false; break;
                        }
                    }
                } else {                    
                    for (int c_idx = C_min; c_idx <= C_max; c_idx += 2) {
                        if (grid[i - d][c_idx] == grid[i + d][c_idx]) {
                            valid = false; break;
                        }
                    }
                }
                if (!valid) break;
            }
                        
            if (valid) {                
                if (i - R_min <= R_max - i) {
                    R_min = i + 1;
                } else {
                    R_max = i - 1;
                }
                changed = true;
                break;
            }
        }
        
        if (changed) continue;
                
        for (int j = C_min + 1; j < C_max; j += 2) {
            bool valid = true;
                        
            char first_fold = grid[R_min][j];
            for (int r_idx = R_min; r_idx <= R_max; r_idx += 2) {
                if (grid[r_idx][j] != first_fold) {
                    valid = false;
                    break;
                }
            }
            
            if (!valid) continue;
                        
            int D = min(j - C_min, C_max - j);
            for (int d = 1; d <= D; d++) {
                if (d % 2 != 0) {                    
                    for (int r_idx = R_min + 1; r_idx <= R_max - 1; r_idx += 2) {
                        if (grid[r_idx][j - d] == grid[r_idx][j + d]) {
                            valid = false; break;
                        }
                    }
                } else {                    
                    for (int r_idx = R_min; r_idx <= R_max; r_idx += 2) {
                        if (grid[r_idx][j - d] == grid[r_idx][j + d]) {
                            valid = false; break;
                        }
                    }
                }
                if (!valid) break;
            }
                        
            if (valid) {                
                if (j - C_min <= C_max - j) {
                    C_min = j + 1;
                } else {
                    C_max = j - 1;
                }
                changed = true;
                break;
            }
        }
    }
        
    if (R_min == R_max && C_min == C_max) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}