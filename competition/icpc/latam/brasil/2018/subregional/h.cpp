#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define sz(a) (int) (a).size()
#define ll long long

const int MAX = 100005;

vector<int> pi(const string& s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < sz(s); i++) {
        while (j > 0 && s[j] != s[i]) j = p[j-1];
        if (s[j] == s[i]) j++;
        p[i] = j;
    }
    return p;
}

int count_occ(const string& text, const string& pattern, const vector<int>& p) {
    if (pattern.empty() || text.length() < pattern.length()) return 0;
    int count = 0;
    for (int i = 0, j = 0; i < sz(text); i++) {
        while (j > 0 && text[i] != pattern[j]) j = p[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == sz(pattern)) {
            count++;
            j = p[j - 1];
        }
    }
    return count;
}

string P, P_rev;
int P_len;
vector<int> pi_P, pi_P_rev;

struct Node {
    int len;
    ll ans_lr, ans_rl;
    string pref, suff;
        
    Node() : len(0), ans_lr(0), ans_rl(0), pref(""), suff("") {}
};

Node reverse_node(Node A) {
    if(A.len == 0) return A;
    swap(A.ans_lr, A.ans_rl);
    swap(A.pref, A.suff);
    reverse(all(A.pref));
    reverse(all(A.suff));
    return A;
}

namespace seg {
    Node tree[4 * MAX];
    int n;

    Node merge(const Node& L, const Node& R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;
        
        Node res;
        res.len = L.len + R.len;
        res.ans_lr = L.ans_lr + R.ans_lr;
        res.ans_rl = L.ans_rl + R.ans_rl;
        
        string mid = L.suff + R.pref;
        res.ans_lr += count_occ(mid, P, pi_P);
        res.ans_rl += count_occ(mid, P_rev, pi_P_rev);
        
        res.pref = L.pref;
        if (L.len < P_len - 1) {
            res.pref += R.pref;
            if (sz(res.pref) > P_len - 1) res.pref.resize(P_len - 1);
        }
                
        res.suff = R.suff;
        if (R.len < P_len - 1) {
            res.suff = L.suff + res.suff;
            if (sz(res.suff) > P_len - 1) res.suff = res.suff.substr(sz(res.suff) - (P_len - 1));
        }
        return res;
    }

    void build(const string& s_hld, int p = 1, int l = 0, int r = n - 1) {
        if (l == r) {
            tree[p].len = 1;
            string c(1, s_hld[l]);
            tree[p].ans_lr = count_occ(c, P, pi_P);
            tree[p].ans_rl = count_occ(c, P_rev, pi_P_rev);
            tree[p].pref = (P_len > 1) ? c : "";
            tree[p].suff = (P_len > 1) ? c : "";
            return;
        }
        int m = (l + r) / 2;
        build(s_hld, 2 * p, l, m);
        build(s_hld, 2 * p + 1, m + 1, r);
        tree[p] = merge(tree[2 * p], tree[2 * p + 1]);
    }

    Node query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        if (a <= l && r <= b) return tree[p];
        if (b < l || r < a) return Node();
        int m = (l + r) / 2;
        return merge(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
    }

    void update(int pos, char x, int p = 1, int l = 0, int r = n - 1) {
        if (l == r) {
            string c(1, x);
            tree[p].ans_lr = count_occ(c, P, pi_P);
            tree[p].ans_rl = count_occ(c, P_rev, pi_P_rev);
            tree[p].pref = (P_len > 1) ? c : "";
            tree[p].suff = (P_len > 1) ? c : "";
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(pos, x, 2 * p, l, m);
        else update(pos, x, 2 * p + 1, m + 1, r);
        tree[p] = merge(tree[2 * p], tree[2 * p + 1]);
    }
}

namespace hld {
    vector<int> g[MAX];
    int pos[MAX], sz[MAX], depth[MAX];
    int pai[MAX], h[MAX], t;

    void dfs_sz(int k, int p = -1, int d = 0) {
        sz[k] = 1; pai[k] = p; depth[k] = d;
        for (auto& i : g[k]) {
            if (i != p) {
                dfs_sz(i, k, d + 1);
                sz[k] += sz[i];
                if (sz[i] > sz[g[k][0]] || g[k][0] == p) swap(i, g[k][0]);
            }
        }
    }

    void dfs_hld(int k, int p = -1) {
        pos[k] = t++;
        for (auto& i : g[k]) {
            if (i != p) {
                h[i] = (i == g[k][0] ? h[k] : i);
                dfs_hld(i, k);
            }
        }
    }

    void build(const string& s) {
        t = 0;
        dfs_sz(0);
        h[0] = 0;
        dfs_hld(0);
                
        string s_hld(sz(s), ' ');
        for (int i = 0; i < sz(s); i++) {
            s_hld[pos[i]] = s[i];
        }
        
        seg::n = t;
        seg::build(s_hld);
    }

    ll query_path(int u, int v) {
        Node left_path = Node();
        Node right_path = Node();

        while (h[u] != h[v]) {
            if (depth[h[u]] > depth[h[v]]) {
                Node chunk = seg::query(pos[h[u]], pos[u]);
                left_path = seg::merge(left_path, reverse_node(chunk));
                u = pai[h[u]];
            } else {
                Node chunk = seg::query(pos[h[v]], pos[v]);
                right_path = seg::merge(chunk, right_path);
                v = pai[h[v]];
            }
        }
        
        if (depth[u] > depth[v]) {
            Node chunk = seg::query(pos[v], pos[u]);
            left_path = seg::merge(left_path, reverse_node(chunk));
        } else {
            Node chunk = seg::query(pos[u], pos[v]);
            right_path = seg::merge(chunk, right_path);
        }

        return seg::merge(left_path, right_path).ans_lr;
    }
    
    void update(int u, char c) {
        seg::update(pos[u], c);
    }
}

signed main() {
    darvem;

    int n, q;
    if (!(cin >> n >> q)) return 0;

    cin >> P;
    P_len = sz(P);
    P_rev = P;
    reverse(all(P_rev));
    
    pi_P = pi(P);
    pi_P_rev = pi(P_rev);

    string s;
    cin >> s;    

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        hld::g[u].push_back(v);
        hld::g[v].push_back(u);
    }

    hld::build(s);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;            
            cout << hld::query_path(u, v) << "\n";
        } else {
            int u;
            char c;
            cin >> u >> c;
            u--;
            hld::update(u, c);
        }        
    }
    return 0;
}