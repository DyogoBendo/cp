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

template <typename T>
class SegmentTree {
public:
    int n;
    vector<T> seg;

    T neutral(){
        return 0;
    }

    T combine(T l, T r){
        return l + r;
    }

    T build(const vector<T> &v, int p, int l, int r) {
        if (l == r) return seg[p] = v[l];
        
        int mid = (l + r) / 2;
        T left = build(v, 2*p, l, mid);
        T right = build(v, 2*p + 1, mid + 1, r);
        return seg[p] = combine(left, right);
    }

    T update(int k, T u, int p, int l, int r) {
        if (l == r) return seg[p] = u;

        int mid = (l + r) / 2;
        T left = seg[2*p], right = seg[2*p + 1];

        if (k <= mid)left = update(k, u, 2*p, l, mid);
        else right = update(k, u, 2*p + 1, mid + 1, r);
        
        return seg[p] = combine(left, right);
    }

    T query(int a, int b, int p, int l, int r) {
        if (l > b || r < a) return neutral();
        if (l >= a && r <= b) return seg[p];
        int mid = (l + r) / 2;
        T left = query(a, b, 2*p, l, mid);
        T right = query(a, b, 2*p + 1, mid + 1, r);
        return combine(left, right);
    }

    SegmentTree(const vector<T> &v) {
        n = (int)v.size();
        seg.assign(4*n, neutral());
        if (n > 0) build(v, 1, 0, n-1);
    }

    void update(int idx, T val) {
        update(idx, val, 1, 0, n-1);
    }

    T query(int l, int r) {
        return query(l, r, 1, 0, n-1);
    }
};


signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> toin(n), tout(n);        
    vector<ll> tour;

    function<void(int, int)> dfs = [&](int curr, int p){
        toin[curr] = tour.size();
        tour.push_back(v[curr]);

        for(auto e : g[curr]) if(e != p) dfs(e, curr);

        tout[curr] = tour.size();
        tour.push_back(0);
    };

    dfs(0, 0);

    SegmentTree<ll> seg(tour);

    while(q--){
        int op, s, x;
        cin >> op >> s;
        s--;
        if(op == 1){
            cin >> x;            
            seg.update(toin[s], x);
        } else{            
            cout << seg.query(toin[s], tout[s]) << endl;
        }
    }
}