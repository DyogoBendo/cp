#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

typedef tuple<int, int, int> ti;

int main(){
    setIO("mootube");

    int n, q;
    cin >> n >> q;

    vector<ti> edges;
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.rbegin(), edges.rend());

    vector<ti> queries;
    for(int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;
        queries.push_back({k, v, i});
    }    
    sort(queries.rbegin(), queries.rend());

    vector<int> v(n+1), sz(n+1, 1);
    iota(v.begin(), v.end(), 0);

    function<int(int)> find = [&](int x){
        if(x != v[x]) return v[x] = find(v[x]);
        return x;
    };

    function<void(int, int)> un = [&](int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x, y);
        v[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;        
    };
    
    vector<int> ans(q);

    int curr = 0;
    for(int i = 0; i < q;i++){
        auto [r, v, idx] = queries[i];

        while(curr < edges.size() && get<0>(edges[curr]) >=r){
            auto [_, x, y] = edges[curr];
            un(x, y);
            curr++;
        }
        ans[idx] = sz[find(v)] - 1;
    }

    for(auto a : ans) cout << a << endl;
}