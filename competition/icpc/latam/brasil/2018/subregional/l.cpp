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

int d[MAX], p[MAX], pp[MAX];

void set_root(int i) { p[i] = pp[i] = i, d[i] = 0; }

void add_leaf(int i, int u) {
	p[i] = u, d[i] = d[u]+1;
	pp[i] = 2*d[pp[u]] == d[pp[pp[u]]]+d[u] ? pp[pp[u]] : u;
}

int kth(int i, int k) {
	int dd = max(0, d[i]-k);
	while (d[i] > dd) i = d[pp[i]] >= dd ? pp[i] : p[i];
	return i;
}

int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	while (d[a] > d[b]) a = d[pp[a]] >= d[b] ? pp[a] : p[a];
	while (a != b) {
		if (pp[a] != pp[b]) a = pp[a], b = pp[b];
		else a = p[a], b = p[b];
	}
	return a;
}

int dist(int a, int b) { return d[a]+d[b]-2*d[lca(a,b)]; }

vector<int> g[MAX];

void build(int i, int pai=-1) {
	if (pai == -1) set_root(i);
	for (int j : g[i]) if (j != pai) {
		add_leaf(j, i);
		build(j, i);
	}
}

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    build(0);    

    while(q--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--, b--, x--, y--;
        
        int lca_ab = lca(a, b);
        int lca_xy = lca(x, y);
        
        int lca_ax = lca(a, x);
        int lca_ay = lca(a, y);
        
        int lca_bx = lca(b, x);
        int lca_by = lca(b, y);

        int lca_a = d[lca_ax] > d[lca_ay] ? lca_ax : lca_ay;
        int lca_b = d[lca_bx] > d[lca_by] ? lca_bx : lca_by;

        int lca_mn = d[lca_ab] > d[lca_xy] ? lca_ab : lca_xy;
        int l = lca(lca_ab, lca_xy);
        if(l != lca_ab and l != lca_xy){
            cout << 0 << endl;
            continue;
        }

        int ans = 0;
        int cnt = 0;
        dbg(lca_a+1, lca_b+1, lca_mn+1);
        if(d[lca_mn] <= d[lca_a]) ans += dist(lca_a, lca_mn) + 1, cnt++;
        if(d[lca_mn] <= d[lca_b]) ans += dist(lca_b, lca_mn) + 1, cnt++;

        dbg(cnt, dist(lca_b, lca_mn));
        if(cnt == 2) ans--;        

        cout << ans  << endl;
    }
}