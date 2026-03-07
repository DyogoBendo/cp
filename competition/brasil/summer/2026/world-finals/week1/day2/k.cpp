#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e8;

struct SegTree {
    int n;
    vector<int> tree, lazy;
    SegTree(int n) : n(n), tree(4 * n + 1, 0), lazy(4 * n + 1, 0) {}

    void push(int node) {
        if (lazy[node] != 0) {
            tree[2 * node] += lazy[node];
            lazy[2 * node] += lazy[node];
            tree[2 * node + 1] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void build(int node, int start, int end, const vector<int>& a) {
        if (start == end) {
            tree[node] = (a[start] == 0) ? 0 : -INF;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, a);
        build(2 * node + 1, mid + 1, end, a);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query() {
        return tree[1];
    }
};

void solve() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> a(n + 1);
        vector<vector<int>> idx_asc(n + 1), idx_desc(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] > 0) {
                idx_asc[a[i]].push_back(i);
                idx_desc[a[i]].push_back(i);
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            reverse(idx_desc[i].begin(), idx_desc[i].end());
        }

        // 1. Prefix DP Updates
        vector<int> dp_pref(n + 2, n + 1);
        dp_pref[0] = 0;
        vector<vector<pair<int, int>>> pref_updates(n + 2);
        
        for (int v = 1; v <= n; ++v) {
            for (int i : idx_desc[v]) {
                int low = 0, high = n, L = 0;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (dp_pref[mid] < i) { L = mid; low = mid + 1; }
                    else { high = mid - 1; }
                }
                int old_idx = dp_pref[L + 1];
                if (i < old_idx) {
                    dp_pref[L + 1] = i;
                    pref_updates[v].push_back({i, old_idx - 1});
                }
            }
        }

        // 2. Suffix DP Updates
        vector<int> dp_suff(n + 2, 0);
        dp_suff[0] = n + 1;
        vector<vector<pair<int, int>>> suff_updates(n + 2);
        
        for (int v = n; v >= 1; --v) {
            for (int i : idx_asc[v]) {
                int low = 0, high = n, L = 0;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (dp_suff[mid] > i) { L = mid; low = mid + 1; }
                    else { high = mid - 1; }
                }
                int old_idx = dp_suff[L + 1];
                if (i > old_idx) {
                    dp_suff[L + 1] = i;
                    suff_updates[v].push_back({old_idx + 1, i});
                }
            }
        }

        // 3. Base LIS Ignoring Zeroes
        vector<int> base_lis_arr;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) {
                auto it = lower_bound(base_lis_arr.begin(), base_lis_arr.end(), a[i]);
                if (it == base_lis_arr.end()) base_lis_arr.push_back(a[i]);
                else *it = a[i];
            }
        }
        int base_LIS = base_lis_arr.size();

        // 4. Scanline Execution
        SegTree st(n);
        st.build(1, 1, n, a);

        // Apply all suffix constraints for elements > 1 initially
        for (int v = 2; v <= n; ++v) {
            for (auto& p : suff_updates[v]) {
                st.update(1, 1, n, p.first, p.second, 1);
            }
        }

        long long total_sum = 0;
        for (long long x = 1; x <= n; ++x) {
            int max_with_zero = st.query() + 1;
            long long fx = max((long long)base_LIS, (long long)max_with_zero);
            total_sum += x * fx;

            // Shift scanline to x + 1
            // Apply elements equal to x to prefix DP
            for (auto& p : pref_updates[x]) {
                st.update(1, 1, n, p.first, p.second, 1);
            }
            // Undo elements equal to x + 1 from suffix DP
            if (x + 1 <= n) {
                for (auto& p : suff_updates[x + 1]) {
                    st.update(1, 1, n, p.first, p.second, -1);
                }
            }
        }

        cout << total_sum << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}