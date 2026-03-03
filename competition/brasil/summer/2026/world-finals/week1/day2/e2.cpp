#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int n;
vector<vector<int>> adj;
vector<int> sz;
vector<vector<vector<int>>> DP;

void dfs(int u, int p) {
    // T represents the auxiliary DP: T[M][S]
    vector<int> T(1, 1);
    int T_width = 1;
    int sz_u = 1;

    for (int c : adj[u]) {
        if (c == p) continue;
        dfs(c, u);
        int sz_c = sz[c];
        auto& dp_c = DP[c];

        // Precompute prefix sums for the child's DP to optimize the merge
        int cols_SumDP = sz_c + 1;
        vector<int> SumDP((sz_u + 1) * cols_SumDP, 0);
        for (int M = 0; M <= sz_u; ++M) {
            for (int f = 0; f <= sz_c; ++f) {
                long long sum = 0;
                int limit = min(M - 1, sz_c);
                for (int m = 0; m <= limit; ++m) {
                    sum += dp_c[m][f];
                }
                SumDP[M * cols_SumDP + f] = sum % MOD;
            }
        }

        // Precompute prefix sums for the running auxiliary DP (T)
        int cols_SumT = sz_u + 1;
        vector<int> SumT((sz_c + 1) * cols_SumT, 0);
        for (int m = 0; m <= sz_c; ++m) {
            for (int S = 0; S < sz_u; ++S) {
                long long sum = 0;
                int limit = min(m, sz_u - 1);
                for (int M = 0; M <= limit; ++M) {
                    sum += T[M * T_width + S];
                }
                SumT[m * cols_SumT + S] = sum % MOD;
            }
        }

        // Tree knapsack transition
        int next_width = sz_u + sz_c + 1;
        vector<int> next_T(next_width * next_width, 0);

        // Case 1: Max MEX comes from the running prefix (M > m)
        for (int M = 0; M < sz_u; ++M) {
            for (int S = 0; S < sz_u; ++S) {
                int t_val = T[M * T_width + S];
                if (!t_val) continue;
                for (int f = 0; f <= sz_c; ++f) {
                    int val = SumDP[M * cols_SumDP + f];
                    if (val) {
                        next_T[M * next_width + (S + f)] = (next_T[M * next_width + (S + f)] + 1LL * t_val * val) % MOD;
                    }
                }
            }
        }

        // Case 2: Max MEX comes from the current child (m >= M)
        for (int m = 0; m <= sz_c; ++m) {
            for (int f = 0; f <= sz_c; ++f) {
                int dp_val = dp_c[m][f];
                if (!dp_val) continue;
                for (int S = 0; S < sz_u; ++S) {
                    int val = SumT[m * cols_SumT + S];
                    if (val) {
                        next_T[m * next_width + (S + f)] = (next_T[m * next_width + (S + f)] + 1LL * dp_val * val) % MOD;
                    }
                }
            }
        }

        T = move(next_T);
        T_width = next_width;
        sz_u += sz_c;
    }
    sz[u] = sz_u;

    // Allocate current node DP states
    DP[u].assign(sz_u + 1, vector<int>(sz_u + 1, 0));
    int diff_cols = sz_u + 2;
    vector<int> diff((sz_u + 1) * diff_cols, 0);

    // Apply the segment sum logic directly to the diagonal slices using a Difference Array
    for (int M = 0; M < sz_u; ++M) {
        for (int S = 0; S < sz_u; ++S) {
            int t_val = T[M * T_width + S];
            if (t_val) {
                int K = 1 + S + M;
                if (K <= sz_u) {
                    diff[K * diff_cols + M] = (diff[K * diff_cols + M] + t_val) % MOD;
                    diff[K * diff_cols + (K + 1)] = (diff[K * diff_cols + (K + 1)] - t_val + MOD) % MOD;
                }
            }
        }
    }

    // Recover actual DP values from the difference array
    for (int K = 0; K <= sz_u; ++K) {
        long long cur = 0;
        for (int b = 0; b <= K; ++b) {
            cur = (cur + diff[K * diff_cols + b]) % MOD;
            DP[u][b][K - b] = cur;
        }
    }
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    sz.assign(n + 1, 0);
    DP.assign(n + 1, vector<vector<int>>());

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    long long ans = 0;
    // The total correct arrays are captured by summing all valid root configurations
    for (int b = 0; b <= n; ++b) {
        for (int F = 0; F <= n; ++F) {
            if (b + F <= n) {
                ans = (ans + DP[1][b][F]) % MOD;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}