#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n), sz(n, 1);
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

    int q;
    cin >> q;
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            un(u, v);
        } else{
            cout << ((int) find(u) == find(v)) << endl;
        }
    }

}