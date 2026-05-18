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

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];

    vector<vector<pair<int, int>>> graph(n+m);
    vector<pair<int, int>> edges;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(grid[i][j] == '.'){
            int v = i;
            int u = n + j;
            int e = edges.size();            
            graph[v].push_back({u, e});
            graph[u].push_back({v, e});
            edges.push_back({i, j});
        }
    }    
    int start = -1;
    int odd_cnt = 0;
    for(int i = 0; i < n+m; i++) if(sz(graph[i])){        
        if(sz(graph[i]) & 1) odd_cnt++;
        if(start == -1 or (sz(graph[i]) & 1)){
            start = i;
        }
    }    

    if(start == -1 or odd_cnt == 1 or odd_cnt > 2){
        cout << "*" << endl;
        return 0;
    }

    vector<int> visited(sz(edges));
    stack<int> st_v, st_e;
    st_v.push(start);

    vector<vector<int>> ans(n, vector<int>(m));
    int cnt= 0;
    while(!st_v.empty()){
        int v = st_v.top();
        bool found = false;
        while(!graph[v].empty()){
            auto [u, e] = graph[v].back(); graph[v].pop_back();
            if(!visited[e]){
                st_e.push(e);
                visited[e] = 1;
                st_v.push(u);
                found = true;
                break;
            }
        }    
        if(!found){
            st_v.pop();
            if(!st_e.empty()){
                cnt++;
                int e = st_e.top(); st_e.pop();
                auto [x, y] = edges[e];
                ans[x][y] = cnt;
            }
        }
    }

    if(cnt!= sz(edges)){
        cout << "*" << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << ans[i][j] << " ";
        cout << endl;
    } 

}