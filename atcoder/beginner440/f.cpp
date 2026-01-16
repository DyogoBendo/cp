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

#define int long long

const int MAXA = 1e6 + 10;

struct Node{
    ll s;
    int c1;
    int c2;
    int mnc2;

    Node(){
        s = 0LL;
        c1 = 0;
        c2 = 0;
        mnc2 = 1e9;
    }

    Node(ll sx, int c1x, int c2x, int mnc2x): s(sx), c1(c1x), c2(c2x), mnc2(mnc2x){        
    }

    inline Node operator+(const Node& a) const {
        return {s+a.s, c1 + a.c1, c2 + a.c2, min(a.mnc2, mnc2)};
    }

};

template <typename T>
class SegmentTree {
public:
    int n;
    vector<T> seg;

    T neutral(){
        return Node();
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

void solve(){
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> horses(n);
    vector<Node> v(MAXA);

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        horses[i] = {a, b};

        v[a].s += a;
        if(b == 1) v[a].c1++;
        else v[a].c2++;

        if(v[a].c2) v[a].mnc2 = a;
    }

    SegmentTree<Node> seg(v);

    while(q--){
        int w, x, y;
        cin >> w >> x >> y;        

        auto [preva, prevb] = horses[w-1];

        if(prevb == 1) v[preva].c1--;
        else v[preva].c2--;
        v[preva].s -= preva;
        if(!v[preva].c2) v[preva].mnc2 = 1e9;        

        if(y == 1) v[x].c1++;
        else v[x].c2++;
        v[x].s += x;
        if(v[x].c2) v[x].mnc2 = x;
        
        horses[w-1] = {x, y};

        seg.update(preva, v[preva]);
        seg.update(x, v[x]);


        auto tot = seg.query(0, MAXA-1);        

        int lo = 0, hi = MAXA;        
        while(lo < hi){
            int m = (hi - lo) / 2 + lo;
            auto curr = seg.query(m, MAXA-1);
            int cnt = curr.c1 + curr.c2;

            if(curr.c1 and cnt >= tot.c2){
                lo = m + 1;
            } else{
                hi = m;
            }
        }
        
        auto duplicate = seg.query(lo-1, MAXA-1);        

        if(tot.c2 and duplicate.c2 == tot.c2){
            duplicate.c2--;
            duplicate.s -= duplicate.mnc2;
        }        
        duplicate.s -= max<ll>((duplicate.c1 + duplicate.c2) - tot.c2, 0) * (lo-1);                
        cout << tot.s + duplicate.s << endl;
    }
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}