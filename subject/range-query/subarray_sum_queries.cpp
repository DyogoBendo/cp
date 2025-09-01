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

struct node{
    ll prf;
    ll suf;
    ll mx;
    ll all;

    node(){prf = suf = mx = all = 0;}
    node(ll x){
        prf = max(x, 0LL);
        suf = max(x, 0LL);
        mx = max(x, 0LL);
        all = x;
    }    
    node(node l, node r){
        mx = max({l.mx, r.mx, l.suf + r.prf});
        prf = max(l.prf, l.all + r.prf);
        suf = max(r.suf, r.all + l.suf);
        all = l.all + r.all;
    }
};

template <typename T>
class SegmentTree {
public:
    int n;
    vector<T> seg;

    T neutral(){
        return node();
    }

    T combine(T l, T r){
        return node(l, r);
    }

    T build(const vector<ll> &v, int p, int l, int r) {
        if (l == r) return seg[p] = node(v[l]);
        
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

    SegmentTree(const vector<ll> &v) {
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

    int n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    SegmentTree<node> seg(v);

    while(m--){
        ll k, x;
        cin >> k >> x;

        seg.update(k-1, node(x));
        cout << seg.query(0, n-1).mx << endl;
    }

}