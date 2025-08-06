#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD = 1e9+7;

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c});
    }

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    pq.push({0, 0, -1});
    vector<ll> dst(n, -1), cnt(n), mn(n, MOD), mx(n);    
    while(!pq.empty()){
        auto [d, v, p] = pq.top(); pq.pop();                

        if(dst[v] != -1){
            if(d == dst[v]){                
                cnt[v] = (cnt[p] + cnt[v]) % MOD;
                mn[v] = min(mn[v], mn[p] + 1);
                mx[v] = max(mx[v], mx[p] + 1);
            }   
            continue;
        }
        dst[v] = d;        
        mn[v] = p != -1? min(mn[v], mn[p] + 1) : 0;
        mx[v] = p != -1? max(mx[v], mx[p] + 1) : 0;
        cnt[v] = p != -1 ? (cnt[p] + cnt[v]) % MOD : 1;

        for(auto [u, w] : g[v]){
            pq.push({w+d, u, v});
        }
    }
    cout << dst.back() << " " << cnt.back() << " " << mn.back() << " " << mx.back() << endl;
}