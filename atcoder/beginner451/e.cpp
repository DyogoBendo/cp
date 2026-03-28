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

void solve(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> edges;
    vector<vector<int>> original(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w;
            cin >> w;
            edges.push_back({w, i, j});
            original[i][j] = w;
        }
    }

    sort(edges.begin(), edges.end());

    dsu d(n);

    vector<tuple<int, int, int>> real_edges;

    for(auto [w, i, j] : edges){
        if(d.find(i) != d.find(j)){
            d.unite(i, j);
            real_edges.push_back({w, i, j});
        }                
    }

    vector<vector<pair<int, int>>> tree(n);
    for(auto [w, i, j] : real_edges){
        tree[i].push_back({j, w});
        tree[j].push_back({i, w});
    }

    vector<int> distance(n);
    function<void(int, int, int)> dfs = [&](int curr, int p, int cost){
        distance[curr] = cost;
        for(auto [e, w] : tree[curr]) if(e != p){
            dfs(e, curr, cost + w);
        }
    };

    bool possible = true;
    for(int i = 0; i < n; i++){
        dfs(i, i, 0);

        for(int j = i+1; j < n; j++) if(distance[j] != original[i][j]) possible = false;
    }

    cout << (possible ? "Yes" : "No") << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}