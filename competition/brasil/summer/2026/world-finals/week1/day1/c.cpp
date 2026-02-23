#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

vector<int> groups, group_sz, group_squares;

ll calc(ll n){
    return (n*(n-1)) / 2;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    groups.resize(n);
    group_sz.resize(n);
    group_squares.resize(n);

    for(int i = 0; i < n; i++) groups[i] = i;

    for (int i=0; i<k; i++){
        int x;
        cin >> x;
        x--;
        
        group_squares[x]++;
    } 

    vector<tuple<int, int, int>> edges;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;

        edges.push_back(make_tuple(c, b, a));
    }

    ll curr_ans = 0;

    function<int(int)> find = [&](int a){
        if(groups[a] != a) return groups[a] = find(groups[a]);
        else return a;
    };

    function<void(int, int)> unite = [&](int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(group_sz[a] < group_sz[b]) a = b; 

        curr_ans -= calc(group_squares[b]);
        curr_ans -= calc(group_squares[a]);
        group_squares[a] += group_squares[b];
        groups[b] = a;
        curr_ans += calc(group_squares[a]);
    };

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);

    for(int i = 0; i < q; i++){
        int d;
        cin >> d;        
        queries[i] = {d, i};
    }

    sort(edges.rbegin(), edges.rend());
    sort(queries.rbegin(), queries.rend());

    vector<ll> ans(q);

    int nxt_edge = 0;
    for(int i = 0; i < q; i++){
        auto [d, qi] = queries[i];        
        while(nxt_edge < m and get<0>(edges[nxt_edge]) >= d){
            auto [w, a, b] = edges[nxt_edge];
            unite(a, b);
            nxt_edge++;
        }
        ans[qi] = curr_ans;
    }

    for(int i = 0; i < q; i++) cout << ans[i] << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}