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

const int MAXN = 1e3 + 10;

char grid[MAXN][MAXN];
int visited[MAXN][MAXN];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

signed main(){
    darvem;

    int h, w;
    cin >> h >> w;

    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> grid[i][j];

    function<bool(int, int)> dfs = [&](int x, int y){
        if(x < 0 or x >= h or y < 0 or y >= w) return false;
        if(grid[x][y] == '#') return true;
        if(visited[x][y]) return true;
        visited[x][y] = 1;

        bool result = true;
        for(int i = 0; i < 4; i++){
            result &= dfs(x + dx[i], y + dy[i]);
        }   
        return result;
    };

    int cnt = 0;
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++){
        if(!visited[i][j] and grid[i][j] == '.')cnt += dfs(i, j);
    } 

    cout << cnt << endl;
}