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

int query(int x, int y){
    char c;
    cout << "? " << x << " " << y << endl;
    cin >> c;

    return c == 'B';
}

void answer(int c, vector<pair<int, int>> v){
    cout << "! " << (c ? 'B' : 'W');
    for(auto [x, y] : v){
        cout << " "<< x << " " << y;
    }
    cout << endl;
}

int d[] = {1, 0, -1};

const int MAXN = 1000;

int grid[MAXN][MAXN];

signed main(){
    darvem;
    int t, n;
    cin >> t >> n;

    while(t--){            
        vector<pair<int, int>> black, white;
        int x = 300, y = 300;
        int c = query(x, y);
        grid[x][y] = (c?2 :3);
    
        pair<int, int> rigth_w, rigth_b; 
    
        if(c == 0) white.push_back({x, y}), rigth_w = {x, y};
        else black.push_back({x, y}), rigth_b = {x, y};
    
        queue<pair<int, int>> candidates;
    
        while(sz(black) < n and sz(white) < n){
            int xq, yq;

            dbg(sz(candidates));
            if(candidates.empty()){
                if(sz(black) < sz(white)) black.clear();
                else white.clear();
                    
                if (sz(white) == 0) xq = rigth_b.first, yq = rigth_b.second;
                else xq = rigth_w.first, yq = rigth_w.second;            
                xq++;            
            } else{
                tie(xq, yq) = candidates.front(); candidates.pop();   
            } 
            dbg(xq, yq);                                 
            c = query(xq, yq);
            grid[xq][yq] = c ? 2 : 3;
    
            if(c == 1){
                if(!sz(black) or xq > rigth_b.first) rigth_b = {xq, yq};
                black.push_back({xq, yq});
            } else{
                if(!sz(white) or xq > rigth_w.first) rigth_w = {xq, yq};
                white.push_back({xq, yq});
            }                              
            
            for(int i = 0; i < 3; i++){
                int dx = d[i];
                for(int j = 0; j < 3; j++){
                    int dy = d[j];  
                    int gx = dx + xq;
                    int gy = dy + yq;
                    
                    if(grid[gx][gy]) continue;
                    
                    int cntb = 0;
                    int cntw = 0;
                    for(int a = 0; a < 3; a++){
                        for(int b = 0; b < 3; b++){
                            if(grid[d[a] + gx][d[b] + gy] == 2) cntb++;
                            else if(grid[d[a] + gx][d[b] + gy] == 3) cntw++;
                        }
                    }

                    if(cntb and cntw){
                        dbg(gx, gy);
                        if(!candidates.empty()) dbg(candidates.front().first);
                        candidates.push({gx, gy});
                        grid[gx][gy] = 1;            
                    }         
                }
            }        
        }
    
        if(sz(black) == n) answer(1, black);
        else answer(0, white);

        for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) grid[i][j] = 0;
    }

}