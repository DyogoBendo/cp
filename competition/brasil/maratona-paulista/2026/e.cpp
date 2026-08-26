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

const int MAX = 1e5 + 10;

vector<pair<int, int> > g[MAX];
int pos[MAX], sz[MAX];
int sobe[MAX], pai[MAX];
int h[MAX], v[MAX], t;
ll soma[MAX];

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {              
        if(!lazy[p]) return;    
		seg[p] = soma[r+1] - soma[l] - seg[p];
		if (l != r) lazy[2*p] ^= lazy[p], lazy[2*p+1] ^= lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {        
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];        
		if (b < l or r < a) return 0;        
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] ^= 1;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;        

		return seg[p] = update(a, b, 2*p, l, m) +
			update(a, b, 2*p+1, m+1, r);
	}
};

void build_hld(int k, int p = -1, int f = 1) {
    v[pos[k] = t++] = sobe[k]; sz[k] = 1;
    for (auto& i : g[k]) if (i.first != p) {
        auto [u, w] = i;
        sobe[u] = w; pai[u] = k;
        h[u] = (i == g[k][0] ? h[k] : u);
        build_hld(u, k, f); sz[k] += sz[u];

        if (sz[u] > sz[g[k][0].first] or g[k][0].first == p)
            swap(i, g[k][0]);
    }
    if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
}
void build(int root = 0) {
    t = 0;
    build_hld(root);
    seg::build(t, v);
    for(int i = 1; i <= t; i++) soma[i] = soma[i-1] + v[i-1];    
}
ll query_path(int a, int b) {
    if (a == b) return 0;
    if (pos[a] < pos[b]) swap(a, b);

    if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
    return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
}
void update_path(int a, int b) {
    if (a == b) return;
    if (pos[a] < pos[b]) swap(a, b);

    if (h[a] == h[b]) return (void)seg::update(pos[b]+1, pos[a]);
    seg::update(pos[h[a]], pos[a]); update_path(pai[h[a]], b);
}

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n-1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    build(0);

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;        
        update_path(a, b);
        
        cout << seg::seg[1] << endl;
    }
}
