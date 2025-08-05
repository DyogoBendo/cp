#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

#define ll long long

namespace segtree {
    const int MAX = 200010;
    int seg[2 * MAX];
    int n;

    void build() {
        for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
    }

    int query(int a, int b) {
        int ret = 0;
        for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
            if (a % 2 == 1) ret += seg[a];
            if (b % 2 == 0) ret += seg[b];
        }
        return ret;
    }

    void update(int p, int x) {
        seg[p += n] = x;
        while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
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

void solve_ord(){
    int n;
    cin >> n;

    ll ans = 0;
    ord_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ans += i - s.order_of_key(x);        
        s.insert(x);
    }
    cout << ans << endl;      
}

void solve_seg(){
    int n;
    cin >> n;
    segtree::n = n;
    for(int i = 0; i < n; i++) segtree::update(i, 0);

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }    
    sort(v.begin(), v.end());
    vector<int> v2(n);
    for(int i = 0; i < n; i++){
        v2[v[i].second] = i;
    }


    ll ans = 0;
    for(int i = 0; i < n; i++){                
        ans += segtree::query(v2[i], n-1);
        segtree::update(v2[i], 1);
    }

    cout << ans << endl;
}

void solve_bit(){
    int n;
    cin >> n;
    Bit bit(n);

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }    
    sort(v.begin(), v.end());
    vector<int> v2(n);
    for(int i = 0; i < n; i++){
        v2[v[i].second] = i;
    }


    ll ans = 0;
    for(int i = n-1; i >=0; i--){                
        ans += bit.pref(v2[i]);
        bit.update(v2[i], 1);
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve_bit();
    }
}