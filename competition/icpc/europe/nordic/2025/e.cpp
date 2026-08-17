#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio();
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) a.size())

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while(sz(s) && s[0] != ','); 
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;
vector<vector<char>> grid;

void printAns(vector<vector<char>> &ans){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &cur){
    if(visited[i][j]) return;
    visited[i][j] = 1;
    for(int a = 0; a < 4; a++){
        int gx = dx[a] + i;
        int gy = dy[a] + j;
        
        if(gx < 0 or gx >= n or gy < 0 or gy >= m) continue;
        if(cur[gx][gy] != cur[i][j]) continue;
        
        dfs(gx, gy, visited, cur);
    }
}

int check(vector<vector<char>> &cur){
    vector<vector<int>> vst(n, vector<int>(m));

    int tot = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cur[i][j] == '#') continue;
            if(!vst[i][j]){
                tot++;
                dfs(i, j, vst, cur);
            } 
        }
    } 

    return tot;
}

bool solve(int halfC, vector<vector<char>> init){

    //tudo A
    vector<vector<char>> base = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(base[i][j] != '#') {
                base[i][j] = 'A';
            }
        }
    }

    // esquerda --> direita
    {
        vector<vector<char>> cur = base;
        int left = halfC;
        for(int col = 0; col < 2 * n - 1; ++col) {
            bool up = col < n; 
            for(int row = up ? n - 1 : 0; up ? row >= 0 : row < n; up ? --row : ++row) {
                if(init[row][col] == '#') continue;
                cur[row][col] = 'B';
                if(init[row][col] == 'C') left--;
                if(left == 0) break;
            }
            if(left == 0) break;
        }
        if(left == 0 && check(cur) == 2) {
            printAns(cur);
            return true;
        }
    }

    // direita --> esquerda
    {
        vector<vector<char>> cur = base;
        int left = halfC;
        for(int col = 2 * n - 2; col >= 0; --col) {
            bool up = col >= n - 1;
            for(int row = up ? n - 1 : 0; up ? row >= 0 : row < n; up ? --row : ++row) {
                if(init[row][col] == '#') continue;
                cur[row][col] = 'B';
                if(init[row][col] == 'C') left--;
                if(left == 0) break;
            }
            if(left == 0) break;
        }
        if(left == 0 && check(cur) == 2) {
            printAns(cur);
            return true;
        }
    }

    // cima p baixo
    {
        vector<vector<char>> cur = base;
        int left = halfC;
        for(int row = 0; row < n; ++row) {
            for(int it = 0; it < 2 * row + 1; ++it) {
                int ind = it;

                if(row != 0) {
                    if(ind == 0) ind = 1;
                    else if(ind == 1) ind = 0;
                }
                int col = n - 1 - row + ind;
                if(init[row][col] == '#') continue;
                cur[row][col] = 'B';
                if(init[row][col] == 'C') left--;
                if(left == 0) break;
            }
            if(left == 0) break;
        }
        if(left == 0 && check(cur) == 2) {
            printAns(cur);
            return true;
        }
    }

    // esquerda --> direita
    {
        vector<vector<char>> cur = base;
        int left = halfC;
        for(int ind = 0; ind < 2 * n - 1; ++ind) {
            for(int row = 0; row < n; ++row) {
                int col = n - 1 - row + ind;
                if(col < 0 || col >= 2 * n - 1) continue;
                if(init[row][col] == '#') continue;
                cur[row][col] = 'B';
                if(init[row][col] == 'C') left--;
                if(left == 0) break;
            }
            if(left == 0) break;
        }
        if(left == 0 && check(cur) == 2) {
            printAns(cur);
            return true;
        }
    }

    // direita --> esquerda
    {
        vector<vector<char>> cur = base;
        int left = halfC;
        for(int ind = 0; ind < 2 * n - 1; ++ind) {
            for(int row = 0; row < n; ++row) {
                int col = n - 1 + row - ind;
                if(col < 0 || col >= 2 * n - 1) continue;
                if(init[row][col] == '#') continue;
                cur[row][col] = 'B';
                if(init[row][col] == 'C') left--;
                if(left == 0) break;
            }
            if(left == 0) break;
        }
        if(left == 0 && check(cur) == 2) {
            printAns(cur);
            return true;
        }
    }

    return false;
}

void solution(){    
    cin >> n;    
    m = 2*n - 1;

    grid.resize(n, vector<char>(m));
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'C') cnt++;
        }
    }

    if(cnt % 2) {
        cout << "impossible\n"; 
        return;
    }

    int halfC = cnt / 2;

    bool possible = solve(halfC, grid);

    if(!possible) cout << "impossible\n";
}

signed main(){
    fastio;

    int cases = 1;
    //cin >> cases;

    for (int i = 0; i < cases; i++)
    {   
        solution();
    }
}