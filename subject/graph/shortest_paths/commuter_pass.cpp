#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int INF = 1e18;
typedef pair<int, int> pii;

int n, m, s, t, u, v;
vector<vector<pii>> g;
vector<int> d1(int st){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});

    vector<int> dst(n, INF);
    while(!pq.empty()){
        auto [d, x] = pq.top(); pq.pop();
        if(dst[x] != INF) continue;        
        dst[x] = d;

        for(auto e : g[x]){
            pq.push({e.second + d, e.first});
        }
    }
    return dst;
}

void dfs(vector<int> &visited, vector<int> &dst_u, vector<int> &dst_v, vector<vector<int>> &parents, vector<int> &dpu, vector<int> &dpv, int curr){
    if(visited[curr]) return;
    visited[curr] = 1;

    for (auto p : parents[curr])
    {
        dfs(visited, dst_u, dst_v, parents, dpu, dpv, p);
        dpu[curr] = min({dst_u[p], dpu[p], dpu[curr]});
        dpv[curr] = min({dst_v[p], dpv[p], dpv[curr]});
    }
    
}

int d2(){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
    vector<int> dst(n, INF), dpu(n, INF), dpv(n, INF), dst_u = d1(u), dst_v = d1(v);    
    
    vector<vector<int>> parents(n);

    pq.push({0, s, -1});
    while(!pq.empty()){
        auto [d, x, p] = pq.top(); pq.pop();
        if(dst[x] != INF){            
            if(dst[x] == d && p != -1) parents[x].push_back(p);                            
            continue;
        }
        
        if(p!= -1) parents[x].push_back(p);
        
        dst[x] = d;
        
        for(auto e : g[x]){
            pq.push({e.second + d, e.first, x});
        }
    }        

    vector<int> visited(n);
    dfs(visited, dst_u, dst_v, parents, dpu, dpv, t);

    int ans = 1e18;
    for(int i = 0; i < n; i++){        
        ans = min({ans, dpu[i] + dst_v[i], dpv[i] + dst_u[i]});        
    }
    return ans;
}


signed main(){
    darvem;

    cin >> n >> m >> s >> t >> u >> v;
    s--;t--;u--;v--;
    g.resize(n);

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    auto dst = d1(u);

    cout << min(dst[v], d2()) << endl;
}