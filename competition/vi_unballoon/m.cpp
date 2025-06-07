#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int LINF = 1e18;

vector<vector<pair<int, int>>> g;
int n, m;
int disjkra(int limit){
    vector<int> d(n);

    for (int i = 0; i < n; i++) d[i] = LINF;
	d[0] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, 0);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : g[u]) if (w < limit && d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}

    return d[n-1];
}

signed main(){
    darvem;

    cin >> n >> m;

    g.resize(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--;v--;
        g[u].push_back({v, w});        
    }
    
    int bst = disjkra(1e9);

    int lo = 0, hi = 1e9;

    while(lo < hi){
        int mid  = (hi - lo) / 2 + lo;

        if(disjkra(mid) > bst){
            lo = mid + 1;
        } else{
            hi = mid;
        }
    }
    cout << bst << " " << hi - 1 << endl;

}