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

#define int long long

int n, m;
int grid[50][50];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

set<set<pair<int, int>>> a1, a2;

signed main(){
    darvem;

    cin >> n >> m;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
        
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        set<pair<int, int>> st;
        st.insert({i, j});
        a1.insert(st);
    }
    for(int k = 1; k < m; k++){
        a2 = a1;
        dbg(a2.size());
        a1.clear();
        for(auto &s : a2){      
            auto s2 = s;      
            for(auto [x, y] : s){
                for(int i = 0; i < 4; i++){
                    int px = x + dx[i];
                    int py = y + dy[i];

                    if(px < 0) continue;
                    if(px >= n) continue;
                    if(py < 0) continue;
                    if(py >= n) continue;
                    if(s.count({px, py})) continue;

                    s2.insert({px, py});
                    a1.insert(s2);
                    s2.erase({px, py});
                }
            }
        }
    }



    int bst = 0;
    for(auto ans : a1){
        if(ans.size() != m){            
            continue;
        } 
        int sum = 0;        
        for(auto x : ans){                 
            sum += grid[x.first][x.second];
        }  
        bst = max(sum, bst);
    }
    cout << bst << endl;
}