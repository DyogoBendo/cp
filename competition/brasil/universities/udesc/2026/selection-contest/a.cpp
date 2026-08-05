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

const int MAX = 200005;
namespace sam {
    int sz, len[2*MAX], link[2*MAX];
    int nxt[2*MAX][26];

    void init() {
        sz = 0;
        len[0] = 0;
        link[0] = -1;
        sz++;
    }

    int extend(int last, int c) {
        int cur = sz++;
        len[cur] = len[last] + 1;
        int at = last;
        while (at != -1 and !nxt[at][c]) {
            nxt[at][c] = cur;
            at = link[at];
        }
        if (at == -1) {
            link[cur] = 0;
            return cur;
        }
        int q = nxt[at][c];
        if (len[q] == len[at] + 1) {
            link[cur] = q;
            return cur;
        }
        int qq = sz++;
        len[qq] = len[at] + 1;
        link[qq] = link[q];
        for (int i = 0; i < 26; i++) nxt[qq][i] = nxt[q][i];
        while (at != -1 and nxt[at][c] == q) {
            nxt[at][c] = qq;
            at = link[at];
        }
        link[q] = link[cur] = qq;
        return cur;
    }
};

struct Bit {
    int n;
    vector<ll> bit;
    Bit(int _n=0) : n(_n), bit(n + 1) {}
    Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
        for (int i = 1; i <= n; i++) {
            bit[i] += v[i - 1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }
    void update(int i, ll x) { // soma x na posicao i
        for (i++; i <= n; i += i & -i) bit[i] += x;
    }
    ll pref(int i) { // soma [0, i]
        ll ret = 0;
        for (i++; i; i -= i & -i) ret += bit[i];
        return ret;
    }
    ll query(int l, int r) {  // soma [l, r]
        return pref(r) - pref(l - 1); 
    }
    int upper_bound(ll x) {
        int p = 0;
        for (int i = __lg(n); i+1; i--) 
            if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
                x -= bit[p += (1 << i)];
        return p;
    }
};

vector<pair<int, char>> adj[MAX];
int pos_trie[MAX];

vector<int> link_adj[2*MAX];
int in_time[2*MAX], out_time[2*MAX], timer_val = 0;

void dfs_link(int u) {
    in_time[u] = timer_val++;
    for (int v : link_adj[u]) {
        dfs_link(v);
    }
    out_time[u] = timer_val - 1;
}

vector<pair<string, int>> queries[MAX];
vector<int> ans;
Bit* bit_tree;

bool isValid(int state) {
    return bit_tree->query(in_time[state], out_time[state]) > 0;
}

void dfs_trie(int u) {
    int state = pos_trie[u];
    bit_tree->update(in_time[state], 1);

    for (auto& q : queries[u]) {
        int st_sam = 0;
        int l = 0;
        int best = 0;
        
        for (char ch : q.first) {
            int c = ch - 'a';
            while (st_sam != -1) {
                int nxt_state = sam::nxt[st_sam][c];
                if (nxt_state != 0 && isValid(nxt_state)) {
                    break; 
                }
                st_sam = sam::link[st_sam];
                if (st_sam != -1) l = sam::len[st_sam];
                else l = 0;
            }
            
            if (st_sam != -1) {
                st_sam = sam::nxt[st_sam][c];
                l++;
            } else {
                st_sam = 0;
                l = 0;
            }
            best = max(best, l);
        }
        ans[q.second] = best;
    }

    for (auto& edge : adj[u]) {
        dfs_trie(edge.first);
    }

    bit_tree->update(in_time[state], -1); 
}

signed main() {
    darvem;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int u;
        char c;
        cin >> u >> c;
        adj[u].push_back({i, c});
    }

    sam::init();

    auto bfs = [&](){
        queue<int> q;
        q.push(0);
        pos_trie[0] = 0;
    
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& edge : adj[u]) {
                int v = edge.first;
                pos_trie[v] = sam::extend(pos_trie[u], edge.second - 'a');
                q.push(v);
            }
        }
    };

    bfs();


    for (int i = 1; i < sam::sz; i++) {
        link_adj[sam::link[i]].push_back(i);
    }
    
    dfs_link(0);

    bit_tree = new Bit(timer_val + 5);

    int q;
    cin >> q;
    ans.resize(q);
    
    for (int i = 0; i < q; i++) {
        int v;
        string s;
        cin >> v >> s;
        queries[v].push_back({s, i});
    }

    dfs_trie(0);

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    delete bit_tree;
    return 0;
}