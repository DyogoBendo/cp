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
        if (l == r){            
            return seg[p] = u;
        } 

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

    int kth(int k, int p, int l, int r){                   
        if(seg[p] < k) return -1;
        if(l == r) return l;

        int mid = (l + r) / 2;
        T left = seg[2*p];
        if(left >= k) return kth(k, 2*p, l, mid);
        return kth(k - left, 2*p+1, mid+1, r);
    }

    int kth(int k){
        return kth(k, 1, 0, n-1);
    }
};


signed main(){
    darvem;

    int q;
    cin >> q;

    vector<pair<char, int>> op(q);
    
    vector<int> v;

    for(int i = 0; i < q; i++){
        cin >> op[i].first >> op[i].second;
        v.push_back(op[i].second);
    }

    sort(v.begin(), v.end());    
    v.erase(unique(v.begin(), v.end()), v.end());
    int cnt = 1;
    map<int, int> mp;
    for(int x : v){        
        if(mp[x] == 0) mp[x] = cnt++;
    }
    
    vector<int> base(mp.size() + 1);
    SegmentTree<int> seg(base);

    for(auto [c, x] : op){           
        if(c == 'I'){        
            seg.update(mp[x], 1);
        } 
        else if(c == 'D'){            
            seg.update(mp[x], 0);
        } 
        else if(c == 'K'){            
            int ans = seg.kth(x);
            if(ans == -1) cout << "invalid" << endl;
            else cout << v[ans-1] << endl;
        } else{
            cout << seg.query(0, mp[x] - 1) << endl;
        }            
    }
    
}