#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int INF = 1e9 + 10;

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

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;    

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    vector<vector<int>> tree(n);    
    
    priority_queue<pair<int, int>> pq;

    pq.push({0, 0});
    vector<int> visited(n, INF);

    while(!pq.empty()){
        auto [w, u]  = pq.top(); pq.pop();
        w = -w;
        if(visited[u] != INF) continue;

        visited[u] = w;        

        for (auto e : graph[u])
        {
            if(visited[e.first] == INF) pq.push({-max(e.second, w), e.first});
        }        
    }

    int d;
    cin >> d;

    vector<int> to_visit(d);
    for (int i = 0; i < d; i++)
    {
        int x;
        cin >> x;
        x--;        
        to_visit[i] = visited[x];
    }

    vector<int> ladders(d);
    for (int i = 0; i < d; i++)
    {
        cin >> ladders[i];
    }

    sort(ladders.begin(), ladders.end());
    sort(to_visit.begin(), to_visit.end());

    int l = 0, ans = 0;
    for (int i = 0; i < d; i++)
    {                
        while(ladders[l] < to_visit[i] && l < d) l ++;                        
        if(l < d && ladders[l] >= to_visit[i]){            
            l ++;            
            ans++;
        } 
    }
    
    cout << ans << endl;
}