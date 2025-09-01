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
        return -1;
    }

    T combine(T l, T r){
        return max(l, r);
    }

    T build(const vector<T> &v, int p, int l, int r) {
        if (l == r) return seg[p] = v[l];
        
        int mid = (l + r) / 2;
        T left = build(v, 2*p, l, mid);
        T right = build(v, 2*p + 1, mid + 1, r);
        return seg[p] = combine(left, right);
    }

    T update(int k, T u, int p, int l, int r) {
        if (l == r) return seg[p] -= u;

        int mid = (l + r) / 2;
        T left = seg[2*p], right = seg[2*p + 1];

        if (k <= mid)left = update(k, u, 2*p, l, mid);
        else right = update(k, u, 2*p + 1, mid + 1, r);
        
        return seg[p] = combine(left, right);
    }

    T query(int x, int p, int l, int r) {
        if(l == r){
            if(x <= seg[p]) return l;
            return -1;
        }
        int mid = (l + r) / 2;
        T left = seg[2*p], right = seg[2*p+1];
        if(left >= x) return query(x, 2*p, l, mid);
        if(right >= x) return query(x, 2*p + 1, mid + 1, r);        
        return -1;
    }

    SegmentTree(const vector<T> &v) {
        n = (int)v.size();
        seg.assign(4*n, neutral());
        if (n > 0) build(v, 1, 0, n-1);
    }

    void update(int idx, T val) {
        update(idx, val, 1, 0, n-1);
    }

    T query(int x) {
        return query(x, 1, 0, n-1);
    }
};


signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<int> hotels(n);
    for(int i = 0; i < n; i++){
        cin >> hotels[i];
    }

    SegmentTree<int> seg(hotels);
        
    for(int i = 0; i < m; i++){
        int r;
        cin >> r;

        int a = seg.query(r);
        if(a != -1) seg.update(a, r);
        cout << a+1 << " ";
    }
    cout << endl;
}