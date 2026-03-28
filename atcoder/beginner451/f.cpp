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

struct dsu {
	vector<int> id, tam, opos;

	dsu(int n) : id(n), tam(n, 1), opos(n, -1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;

		if (tam[a] < tam[b]) swap(a, b);        
		tam[a] += tam[b], id[b] = a;        
	}

    int calc(int a, int b){
        a = find(a);
        b = find(b);

        
        int ao = opos[a];
        int bo = opos[b];        
        if(a == bo) return 0;

        int tao = ao == -1 ? 0 : tam[ao];
        int tbo = bo == -1 ? 0 : tam[bo];

        int prev_black = min(tam[b], tbo) + min(tam[a], tao);

        if(bo != -1) unite(a, bo);
        if(ao != -1) unite(b, ao);

        a = find(a);
        b = find(b);

        opos[a] = b;
        opos[b] = a;        

        return min(tam[a], tam[b]) - prev_black;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    dsu d(n);

    bool possible = true;
    int curr = 0;
    while(q--){
        int u, v;
        cin >> u >> v;
        u--, v--;        

        if(d.find(u) == d.find(v)) possible = false;        
        curr += d.calc(u, v);

        cout << (possible ? curr : -1) << endl;
    }
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}