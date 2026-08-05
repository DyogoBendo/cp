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
	vector<int> id, tam;

	dsu(int n) : id(n), tam(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (tam[a] < tam[b]) swap(a, b);
		tam[a] += tam[b], id[b] = a;
	}
};

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    dsu d(2*n);
    
    for(int i = 0; i < m; i++){
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;
        if(t == 1){
            d.unite(x, y);
            d.unite(x+n, y+n);
        } else{
            d.unite(x, y+n);
            d.unite(y, x+n);
        }

        if(d.find(x) == d.find(x+n) or d.find(y) == d.find(y+n)){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> color(2*n);

    for(int i = 0; i < n; i++){        
        if(!color[d.find(i)]){
            color[d.find(i)] = 1;
            color[d.find(i+n)] = 2;
        }
        cout << color[d.find(i)] << " "; 
    }    
    cout << endl;
}