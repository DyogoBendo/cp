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

namespace seg{
    const int MAX = 2e5 + 10;
	ll seg[4*MAX], lazy_add[4*MAX], lazy_assign[4*MAX];
	int n;
    vector<int> v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy_assign[p] = 0;
        lazy_add[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, vector<int> v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {		
        if(lazy_assign[p] != 0){
            lazy_assign[p] += lazy_add[p];
            seg[p] = lazy_assign[p] *(r-l+1);
            if (l != r) lazy_assign[2*p] = lazy_assign[p], lazy_assign[2*p+1] = lazy_assign[p], lazy_add[2*p] = 0, lazy_add[2*p+1] = 0;
        } else{
            seg[p] += lazy_add[p]*(r-l+1);
            if (l != r) lazy_add[2*p] += lazy_add[p], lazy_add[2*p+1] += lazy_add[p];
        }
		
		lazy_add[p] = 0;
        lazy_assign[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {			
            lazy_assign[p] = x;
            lazy_add[p] = 0;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}

    ll add(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy_add[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = add(a, b, x, 2*p, l, m) +
			add(a, b, x, 2*p+1, m+1, r);
	}
};

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    seg::build(n, v);

    while(q--){
        int op, a, b, x;
        cin >> op >> a >> b;

        a--;b--;
        if(op == 1){
            cin >> x;
            seg::add(a, b, x);
        } else if(op == 2){
            cin >> x;
            seg::update(a, b, x);
        } else{
            cout << seg::query(a, b) << endl;
        }
    }
}