#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    vector<int> groups(n, 0);
    vector<int> sz(n, 1);
    iota(groups.begin(), groups.end(), 0);

    function<int(int)> find = [&](int x){
        if(groups[x] == x) return x;
        return groups[x] = find(groups[x]);
    };

    function <void(int, int)> unite = [&](int x, int y){
        int a = find(x);
        int b = find(y);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        groups[b] = a;
    };

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int prev = -1;
        while(k--){            
            int a;
            cin >> a;
            a--;      
            if(prev != -1){
                unite(a, prev);
            }      
            prev = a;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << sz[find(i)] << " ";
    }    

    cout << endl;    
    
}

signed main(){
    // darvem;
    int t = 1;    

    while(t--) solve();
}