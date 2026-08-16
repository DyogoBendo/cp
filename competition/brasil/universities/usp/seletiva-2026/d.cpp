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

int map_char(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'C') return 2;
    if (c == 'N') return 3;
    if (c == 'D') return 4;
    return -1;
}

const char rev_map[5] = {'A', 'T', 'C', 'N', 'D'};

int id_from_state[6][6][6][6][6];
array<int, 5> state_from_id[126];

struct Outcome {
    array<int, 5> counts;
    double prob;
};
vector<Outcome> outcomes[6];

double dp[6][126];
array<int, 5> best_action[6][126];
string o;

void init(){
    int state_cnt = 0;
    for (int a = 0; a <= 5; a++) {
        for (int b = 0; b <= 5 - a; b++) {
            for (int c = 0; c <= 5 - a - b; c++) {
                for (int d = 0; d <= 5 - a - b - c; d++) {
                    int e = 5 - a - b - c - d;
                    id_from_state[a][b][c][d][e] = state_cnt;
                    state_from_id[state_cnt] = {a, b, c, d, e};
                    state_cnt++;
                }
            }
        }
    }
    
    double fact[10];
    fact[0] = 1;
    for (int i = 1; i < 10; i++) fact[i] = fact[i - 1] * i;

    for (int m = 1; m <= 5; m++) {
        for (int a = 0; a <= m; a++) {
            for (int b = 0; b <= m - a; b++) {
                for (int c = 0; c <= m - a - b; c++) {
                    for (int d = 0; d <= m - a - b - c; d++) {
                        int e = m - a - b - c - d;
                        double p = fact[m] / (fact[a] * fact[b] * fact[c] * fact[d] * fact[e]);
                        p *= pow(2.0 / 6.0, a); 
                        p *= pow(1.0 / 6.0, b); 
                        p *= pow(1.0 / 6.0, c); 
                        p *= pow(1.0 / 6.0, d); 
                        p *= pow(1.0 / 6.0, e); 
                        outcomes[m].push_back({{a, b, c, d, e}, p});
                    }
                }
            }
        }
    }
    
    int req[5] = {0};
    for (char ch : o) {
        req[map_char(ch)]++;
    }
    
    for (int s = 0; s < 126; s++) {
        auto S = state_from_id[s];
        if (S[0] >= req[0] && S[1] >= req[1] && S[2] >= req[2]) {
            dp[0][s] = 1.0;
        } else {
            dp[0][s] = 0.0;
        }
    }
    
    for (int k = 1; k <= 5; k++) {
        for (int s = 0; s < 126; s++) {
            auto S = state_from_id[s];
            
            if (S[0] >= req[0] && S[1] >= req[1] && S[2] >= req[2]) {
                dp[k][s] = 1.0;
                best_action[k][s] = {0, 0, 0, 0, 0}; 
                continue;
            }

            double max_p = -1.0;
            array<int, 5> best_act = {0, 0, 0, 0, 0};
            
            for (int a = 0; a <= S[0]; a++) {
                for (int b = 0; b <= S[1]; b++) {
                    for (int c = 0; c <= S[2]; c++) {
                        for (int d = 0; d <= S[3]; d++) {
                            for (int e = 0; e <= S[4]; e++) {
                                                                
                                if (d > 2 * e) continue;
                                
                                int m = a + b + c + d + e;                                
                                if (m == 0) continue; 

                                double exp_p = 0.0;
                                for (auto& out : outcomes[m]) {
                                    int na = S[0] - a + out.counts[0];
                                    int nb = S[1] - b + out.counts[1];
                                    int nc = S[2] - c + out.counts[2];
                                    int nd = S[3] - d + out.counts[3];
                                    int ne = S[4] - e + out.counts[4];
                                    
                                    int ns = id_from_state[na][nb][nc][nd][ne];
                                    exp_p += out.prob * dp[k - 1][ns];
                                }

                                if (exp_p > max_p) {
                                    max_p = exp_p;
                                    best_act = {a, b, c, d, e};
                                }
                            }
                        }
                    }
                }
            }
            if(max_p < 0) max_p = 0;

            dp[k][s] = max_p;
            best_action[k][s] = best_act;
        }
    }
}

void solve(){
    string s;
    int k;
    cin >> s >> k;

    int cur[5] = {0};
    for (char ch : s) {
        cur[map_char(ch)]++;
    }
    
    int state = id_from_state[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]];

    double ans_p = dp[k][state];
    auto act = best_action[k][state];
    
    string act_str = "";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < act[i]; j++) {
            act_str += rev_map[i];
        }
    }
            
    cout << act_str << " " << fixed << setprecision(10) << ans_p << "\n";
}

signed main() {    
    cin >> o;
    init();
    int t;
    cin >> t;
    while(t--) solve();
}