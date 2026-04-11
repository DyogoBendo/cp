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

const int MAXX = 1e3 + 10;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char get_mov[] = {'R', 'D', 'L', 'U'};

char grid[MAXX][MAXX];
int visited[MAXX][MAXX][4];
tuple<int, int, int> ant[MAXX][MAXX][4];

signed main(){
    darvem;

    int h, w;
    cin >> h >> w;

    int sx, sy, gx, gy;
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;        
        for(int j = 0; j < w; j++){
            if(s[j] == 'S') sx = i, sy = j, s[j] = '.';
            if(s[j] == 'G') gx = i, gy = j, s[j] = '.';
            grid[i][j] = s[j];
        }
    }

    queue<tuple<int, int, int, int>> q;

    for(int i = 0; i < 4; i++){
        q.push({sx, sy, i, 0});
        visited[sx][sy][i] = 1;
        ant[sx][sy][i] = {-1, -1, -1};
    }    

    while(!q.empty()){
        auto [x, y, d, dist] = q.front(); q.pop();               
        
        for(int i = 0; i < 4; i++){
            if(grid[x][y] == 'o' and i != d) continue;
            if(grid[x][y] == 'x' and i == d) continue;    
            
            if(x == 0 and y == 2) dbg(x, y, d, grid[x][y], i);
            

            int ax = x + dx[i];
            int ay = y + dy[i];

            if(ax < 0 or ax >= h) continue;
            if(ay < 0 or ay >= w) continue;
            
            if(!visited[ax][ay][i] and grid[ax][ay] != '#'){
                visited[ax][ay][i] = 1;                
                q.push({ax, ay, i, dist+1});
                ant[ax][ay][i] = {x, y, d};                
            }
        }
    }

    for(int i = 0; i < 4; i++){
        if(visited[gx][gy][i]){
            cout << "Yes" << endl;
            string ans;
            
            int x = gx, y = gy, d = i;
            while(! (x == sx and y == sy)){
                auto [px, py, pd] = ant[x][y][d];
           
                ans += get_mov[d];
                x = px;
                y = py;
                d = pd;                
            }
            reverse(ans.begin(), ans.end());

            cout << ans << endl;
            return 0;
        }
    }
    cout << "No" << endl;

}