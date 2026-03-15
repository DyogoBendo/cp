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

    int n, m, s, f;
    cin >> n >> m >> s >> f;

    vector<vector<tuple<int, int, int>>> g(n+1);
    vector<map<int, int>> visited(n+1);    
    vector<int> visited2(n+1);
    vector<map<int, vector<pair<int, int>>>> mp(n+1);    

    for(int i = 0; i < m; i++){
        int a,ta, b, tb;
        cin >> a >> ta >> b >> tb;

        g[a].push_back({ta, b, tb});
        g[b].push_back({tb, a, ta});        
        mp[a][ta].push_back({b, tb});
        mp[b][tb].push_back({a, ta});   
    }
    
    priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> pq;    
    for(auto [ta, b, tb] : g[s]){        
        pq.push({0, 1, b, tb, s});        
    }
        
    while(!pq.empty()){
        auto [buses, flights, curr, t, prev] = pq.top(); pq.pop();        
        if(visited[curr][t]) continue;   

        visited[curr][t] = 1;
        if(curr == f){
            cout << buses << " " << flights << endl;
            break;
        }         

        if(!visited2[curr]){
            visited2[curr] = 1;            
            for(auto [gate, u, ut] : g[curr]){
                if(visited[u][ut]) continue;                
                pq.push({buses + (gate != t), flights +1, u, ut, curr});                            
            }
        } else{
            for(auto [u, ut] : mp[curr][t]) if(!visited[u][ut]){
                pq.push({buses, flights +1, u, ut, curr});                                            
            }
        }
        
    }    
}