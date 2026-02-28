#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ld long double

// DSU
//
// Une dois conjuntos e acha a qual conjunto um elemento pertence por seu id
//
// find e unite: O(a(n)) ~= O(1) amortizado

struct dsu {
	vector<int> id, sz;

	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

const int MOD = 998244353;
ll expo(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e % 2) ret = ret * b % MOD;
        e /= 2, b = b * b % MOD;
    }
    return ret;
}


signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);

    for(int i = 0; i < m; i++) cin >> edges[i].first >> edges[i].second;

    dsu d(n);

    int components = n;
    ll ans = 0;
    for(int i = m -1; i >=0; i--){
        auto [u, v] = edges[i];
        u--, v--;   
        if(components == 2){
            if(d.find(u) != d.find(v)) ans = (ans + expo(2, i+1)) % MOD;
        } else{
            if(d.find(u) != d.find(v)) components--;
            d.unite(u, v);
        } 
    }

    cout << ans << endl;
}