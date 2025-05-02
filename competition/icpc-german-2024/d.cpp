#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int MAX = 2e5 + 10;
const int MOD = 1e9+7;

struct SegmentTree {
    vector<long long> seg, lazy;
    int n;
    vector<int> v;

    SegmentTree(int n2, vector<int> v2) : n(n2), v(v2) {
        seg.resize(4 * n);
        lazy.resize(4 * n);
        build();
    }

    long long build(int p = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        lazy[p] = 0;
        if (l == r) return seg[p] = v[l];
        int m = (l + r) / 2;
        return seg[p] = build(2 * p, l, m) + build(2 * p + 1, m + 1, r);
    }

    void prop(int p, int l, int r) {
        seg[p] += lazy[p] * (r - l + 1);
        if (l != r) {
            lazy[2 * p] = (lazy[p] + lazy[2*p] + MOD) % MOD;
            lazy[2 * p + 1] = (lazy[p] + lazy[2*p+1] + MOD) % MOD;;
        }
        lazy[p] = 0;
    }

    long long query(int a, int b, int p = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        prop(p, l, r);
        if (a <= l && r <= b) return seg[p];
        if (b < l || r < a) return 0;
        int m = (l + r) / 2;
        return  (query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r)) % MOD;
    }

    long long update(int a, int b, int x, int p = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        prop(p, l, r);
        if (a <= l && r <= b) {
            lazy[p] = (lazy[p] + x + MOD) % MOD;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l || r < a) return seg[p];
        int m = (l + r) / 2;
        return seg[p] = (update(a, b, x, 2 * p, l, m) +
                        update(a, b, x, 2 * p + 1, m + 1, r) + MOD) % MOD;
    }
};

int fast_expo(int a, int k){
    int curr = a;
    int ans = 1;

    while(k){
        if(k % 2){
            ans = (ans * curr) % MOD;             
        }
        curr = curr * curr %MOD;
        k/= 2;
    }
    
    return ans;
}

int curr;
int get_factor(int x){    
    int a = fast_expo(curr, x);
    int b = fast_expo(fast_expo(10000000, MOD - 2), x);     
    return (a * b ) % MOD;
}
int fix(int x){
    int a = fast_expo(10000000, x);
    int b = fast_expo(fast_expo(curr, MOD - 2), x); 
    return (a * b ) % MOD;
}

signed main(){
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, q;
    long double p;
    cin >> n >> q >> p;    
    
    curr = (10000000 - p * 10000000);           

    vector<int> lights(n);
    SegmentTree leftSeg(n, lights);
    SegmentTree rightSeg(n, lights);

    leftSeg.build();
    rightSeg.build();

    while(q--){
        char o;
        cin >> o;

        if(o == '+' || o == '-'){
            int b, x;
            cin >> b >> x;
            x--;            
            int k1 = b*fix(x) % MOD;
            int k2 = b*fix(n - x - 1);            
            
            if(o == '-'){
                k1*= -1;
                k2 *= -1;
            } 
            leftSeg.update(x, n-1, k1);
            rightSeg.update(0, x - 1, k2 % MOD);            
        } else{
            int x;
            cin >> x;
            x--;
            int l =  leftSeg.query(x, x), r = rightSeg.query(x, x);            
            int ans1 = l * get_factor(x) % MOD;
            int ans2 = r * get_factor(n-x-1) % MOD;            
            cout << ((ans1 + ans2) % MOD) << endl;
        }
    }
    
}