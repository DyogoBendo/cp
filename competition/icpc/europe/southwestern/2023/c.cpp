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

const int INF = 1e9;
const int N = 20;

unordered_map<uint64_t, int> memo;

uint64_t lines_with_station[N];
int n, m;

int solve(uint64_t mask) {
    if (__builtin_popcountll(mask) <= 1) return 0;
    if (memo.count(mask)) return memo[mask];
    
    int ans = INF;
    int sz = __builtin_popcountll(mask);
    
    for (int i = 0; i < n; i++) {
        uint64_t mask_yes = mask & lines_with_station[i];
        uint64_t mask_no = mask & ~lines_with_station[i];
                
        if (mask_yes == 0 || mask_no == 0) continue;
        
        ans = min(ans, sz + solve(mask_yes) + solve(mask_no));
    }
    
    return memo[mask] = ans;
}

signed main(){
    darvem;
    cin >> n >> m;    

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int station;
            cin >> station;

            lines_with_station[station] |= (1ULL << i);
        }
    }
        
    uint64_t initial_mask = (1ULL << m) - 1;
    
    int total_questions = solve(initial_mask);
    
    if (total_questions == INF) cout << "not possible\n";
    else cout << fixed << setprecision(12) << (double)total_questions / m << "\n";    
}