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

    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    ll tot = 0;
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(grid[i][j] == '#') tot++;

    auto check = [&](int x){        
        vector<vector<int>> marked(h, vector<int>(w));
        for(int i = 0; i < h; i++) for(int j = 0; j < w; j++){
            if(grid[i][j] == '#' and !marked[i][j]){
                int vis = 0;
                for(int a = i; a < min(i + x, h); a++){
                    for(int b = j; b < min(j + x, w); b++){
                        if(grid[a][b] == '#' and !marked[a][b]) marked[a][b] = 1, vis++;
                    }
                }                
                if(vis < x*x) return false;
            }
        }
        return true;
    };    

    vector<int> candidates;
    for(ll i = 1; i*i <= tot; i++) if(tot % (i*i) == 0) candidates.push_back(i);               

    int ans = 0;
    for(auto c : candidates) if(check(c)) ans = c;        

    cout << ans << endl;
}