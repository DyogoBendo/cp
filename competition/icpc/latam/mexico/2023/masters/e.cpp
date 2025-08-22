#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int INF = 1e17;

signed main(){
    darvem;

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;t--;

    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c});
    }

    vector<int> profit(n);
    for(int i = 0; i < n; i++) cin >> profit[i];

    for(int i = 0; i < n; i++){
        for(auto &[to, c] : g[i]){
            c -= profit[to];
        }
    }

    vector<int> dst(n, INF);
    dst[s] = 0;
    bool cycle = false;
    
    vector<int> visited(n, 0);    
    function<void(int)> dfs = [&](int curr){
        if(visited[curr]) return;
        visited[curr] = 1; 
        for(auto [to, _] : g[curr]) dfs(to);
    };
    
    dfs(s);    

    vector<int> can_reach_t(n);

    auto prev = visited;
    for(int i = 0; i < n; i++){
        if(!prev[i]) continue;                
        for(int i = 0; i < n; i++) visited[i] = 0;
        dfs(i);
        can_reach_t[i] = visited[t];
    }

    for(int i = 0; i < n; i++){        
        for(int j = 0; j < n; j++){            
            if(!can_reach_t[j]) continue;
            for(auto &[to, c] : g[j]){        
                if(dst[j] + c < dst[to]){                    
                    if(i == n-1) cycle = true;
                    dst[to] = dst[j] + c;                    
                }
            }
        }
    }    
    
    if(!can_reach_t[s]){
        cout << "Bad trip" << endl;
    }
    else if(cycle){
        cout << "Money hack!" << endl;
    } else{
        cout << -dst[t] << endl;
    }

}