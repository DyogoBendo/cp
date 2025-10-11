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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve(){
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    vector<pair<int, int>> trashes;
    pair<int, int> takahashi;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '#') trashes.push_back({i, j});
            if(grid[i][j] == 'T') takahashi = {i, j};
        }
    }

    map<vector<pair<int, int>>, int> mp;
    
    queue<pair<vector<pair<int, int>>, int>> q;
    q.push({trashes, 0});
    
    while(!q.empty()){
        auto [curr, dst] = q.front(); q.pop();
        if(mp[curr]) continue;
        mp[curr] = 1;        

        if(curr.size() == 0){
            cout << dst << endl;
            return;
        }
        
        for(int k = 0; k < 4; k++){
            bool possible= true;
            vector<pair<int, int>> t2;
            for(auto [x, y] : curr){
                int gx = x + dx[k];
                int gy = y + dy[k];
    
                if(gx == takahashi.first and gy == takahashi.second) possible= false;
                if(gx >= 0 and gx < h and gy >= 0 and gy < w) t2.push_back({gx, gy});
            }                        
            if(possible) q.push({t2, dst+1});
        }
    }

    cout << -1 << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}