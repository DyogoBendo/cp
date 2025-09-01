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
