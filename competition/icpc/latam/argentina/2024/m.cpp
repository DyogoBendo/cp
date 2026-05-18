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

const int MAX = 2e5 + 10;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n;
    vector<int> v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, vector<int> v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    vector<int> v(n), c(n), p(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) cin >> p[i];

    vector<pair<int, int>> e;
    for(int i = 0; i < n; i++) e.push_back({c[i], i});
    sort(e.rbegin(), e.rend());

    seg::build(n, v);

    int curr = 0;
    ll ans = 0;

    while(sz(e)){
        auto [m, i] = e.back();        
        if(m >= k) break;

        dbg(curr, m, i);

        if(m == curr){
            dbg(i, p[i]);
            seg::update(i, n-1, -p[i]);
        } else{
            ll diff = m - curr;
            ll bst = seg::query(0, n-1);
            dbg(bst, diff);
            if(bst > 0){
                ans += diff * bst;
            }
            seg::update(i, n-1, -p[i]);
            curr = m;
        }
        e.pop_back();
    }
    ll diff = k - curr;
    ll bst = seg::query(0, n-1);
    if(bst > 0){
        ans += diff * bst;
    }
    cout << ans << endl;
}