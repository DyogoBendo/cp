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

const int MAXN = 5e5 + 10;
int cnt[MAXN];

namespace seg {
	ll seg[4*MAXN], lazy[4*MAXN];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
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
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
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
		return seg[p] = min(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}

    // Se tiver uma seg de max, da pra descobrir em O(log(n))
    // o primeiro e ultimo elemento >= val numa range:

    // primeira posicao >= val em [a, b] (ou -1 se nao tem)
    int get_left(int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        //dbg(p, seg[p], l, r);
        if (seg[p] >= 0) return -1;
        if (r == l) return l;
        int m = (l+r)/2;
        int x = get_left(2*p, l, m);
        if (x != -1) return x;
        return get_left(2*p+1, m+1, r);
    }
};

int ac, dr, n;
int calc(int ai, int di){
    return min(n, max(ai - ac, 0) + max(di - dr, 0));
}

void solve(){
    cin >> ac >> dr >> n;
    vector<int> va(n), vb(n), v(n);
    for(int i = 0; i < n; i++) cin >> va[i];
    for(int i = 0; i < n; i++) cin >> vb[i];

    for(int i = 0; i < MAXN; i++){
        cnt[i] = -i;
    }

    seg::build(MAXN, cnt);

    for(int i = 0; i < n; i++){
        v[i] = calc(va[i], vb[i]);
        seg::update(v[i] + 1, MAXN - 1, 1);
    } 

    int q;
    cin >> q;
    while(q--){
        int k, a, d;
        cin >> k >> a >> d;

        k--;
        int x = calc(a, d);

        //dbg(k, v[k], x);

        seg::update(v[k] + 1, MAXN - 1, -1);
        seg::update(x + 1, MAXN-1, 1);
        v[k] = x;

        cout << seg::get_left() - 1 << endl;
    }
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}   