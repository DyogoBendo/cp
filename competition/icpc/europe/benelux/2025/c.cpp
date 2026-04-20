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

const int BLOCK_FACTOR = 212;

pair<int, int> mov[] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}};
const ld inch = 25.4;

bool can_link(tuple<int, int, int, int> t1, tuple<int, int, int, int> t2){
    auto [x1, y1, d1, i1] = t1;
    auto [x2, y2, d2, i2] = t2;


    
    ld dist_center = hypotl(x1 - x2, y1 - y2);
    ld r1 = d1/2.0;
    ld r2 = d2/2.0;
    ld dist_circle = dist_center - r1 - r2;    
    if(i2 == (i1 + 1) % 7  or i2 == (i1 - 1 + 7) % 7){
        dbg(i1, i2, dist_circle, dist_circle <= 2*inch);
    } 
    
    return dist_circle <= 2*inch;
}

signed main(){
    darvem;

    int n;
    cin >> n;

    map<pair<int, int>, vector<tuple<int, int, int, int>>> mp;

    for(int i = 0; i < n; i++){
        int x, y, d;
        cin >> x >> y >> d;

        int mx = x/BLOCK_FACTOR;
        int my = y/BLOCK_FACTOR;

        dbg(i, mx, my);

        mp[{mx, my}].push_back({x, y, d, i});
    }

    vector<vector<int>> g(n);    

    for(auto [pos, group] : mp){
        auto [xg, yg] = pos;        
        for(int i = 0; i < sz(group); i++){            
            for(int j = i+1; j < sz(group); j++){
                if(can_link(group[i], group[j])){
                    g[get<3>(group[i])].push_back(get<3>(group[j]));
                    g[get<3>(group[j])].push_back(get<3>(group[i]));                    
                }
            }

            for(int m = 0; m < 4; m++){
                auto [xd, yd] = mov[m];                
                auto adj_group = mp[{xg + xd, yg + yd}];

                for(int k = 0; k < sz(adj_group); k++){                    
                    auto [xk, yk, dk, ik] = adj_group[k];
                    if(can_link(group[i], adj_group[k])){                        
                        g[get<3>(group[i])].push_back(ik);
                        g[ik].push_back(get<3>(group[i]));
                    }
                }
                
            }
        }        
    }    

    vector<int> visited(n);

    function<void(int)> dfs = [&](int curr){
        if(visited[curr]) return;
        dbg(curr);
        visited[curr] = 1;

        for(auto e : g[curr]) dfs(e);        
    };

    dfs(0);

    int cnt_visited = 0, cnt_2 = 0;
    for(int i = 0; i < n; i++){
        if(visited[i]) cnt_visited++;
        if(g[i].size() >= 2) cnt_2 ++;
        dbg(i, g[i].size());
    }

    dbg(cnt_visited, cnt_2);
    if(cnt_visited == n and (cnt_2 == n or n < 7)) cout << "yes" << endl;
    else cout << "no" << endl;    
}