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
int N;
int m;
const int MAXN = 310;
char grid[MAXN][2*MAXN], grid2[MAXN][2*MAXN];

bool solve(int currA, int currB, int n, int st){    
    dbg("oi", currA, currB, n, st);
    auto bfs = [&](int start_i, int start_j, vector<vector<int>> &visited) {
        queue<pair<int, int>> q;
        q.push({start_i, start_j});
        visited[start_i][start_j] = 1;

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(int a = 0; a < 4; a++){
                int gx = dx[a] + i;
                int gy = dy[a] + j;

                if(gx < 0 or gx >= n or gy < 0 or gy >= m) continue;
                if(grid[gx][gy] != grid[i][j]) continue;
                if(visited[gx][gy]) continue;

                visited[gx][gy] = 1;
                q.push({gx, gy});
            }
        }
    };

    if(st == 0){
        // fill escadinha A
        for(int i = n-1; i >= 0; i--){
            int changed = 0;
            for(int j = 0; j < m and changed < 2; j++){
                if(grid[i][j] == '#') continue;            
                if(currA == 0) goto enda;
                
                if(grid[i][j] == 'C') currA--;                
                grid[i][j] = 'A';
                changed++;
                  
            }
        }

        enda:        
        
        if(grid[1][N-1] == 'A'){
            if(grid[0][N-1] == 'C') currA--;
            grid[0][N-1] = 'A';
        }

        if(currA < 0) return false;
    
        
        // fill escadinha B
        for(int i = n-1; i >= 0; i--){
            int changed = 0;
            for(int j = m-1; j >= 0 and changed < 2; j--){
                if(grid[i][j] == '#') continue;            
                if(currB == 0) goto endb;

                if(grid[i][j] != 'A'){
                    if(grid[i][j] == 'C') currB--;                
                    grid[i][j] = 'B';
                    changed++;
                }
            }
        }        
    
        endb:    
    
        // fill A
        if(currA > 0){
            for(int i = n-1; i >= 0; i--){            
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == '#' or grid[i][j] == 'A' or grid[i][j] == 'B') continue;                
                    
                    if(grid[i][j] == 'C') currA--;                
                    grid[i][j] = 'A';                    
                    
                    if(currA == 0) goto filledA;
                }
            }
        }
    
        filledA:
    
        // fill
        if(currB > 0){
            for(int i = n-1; i >= 0; i--){            
                for(int j = m-1; j >= 0; j--){
                    if(grid[i][j] == '#' or grid[i][j] == 'A' or grid[i][j] == 'B') continue;                
                    
                    if(grid[i][j] == 'C') currB--;                
                    grid[i][j] = 'B';                    
                    
                    if(currB == 0) goto filledB;
                }
            }
        }
    
        
    } else{
        
        // fill escadinha B
        for(int i = n-1; i >= 0; i--){
            int changed = 0;
            for(int j = m-1; j >= 0 and changed < 2; j--){
                if(grid[i][j] == '#') continue;            
                if(currB == 0) goto endb2;
                if(grid[i][j] == 'C'){
                    currB--;
                }
                grid[i][j] = 'B';
                changed++;
            }
        }        
        
        endb2:    
        if(grid[1][N-1] == 'B'){
            if(grid[0][N-1] == 'C') currB--;
            grid[0][N-1] = 'B';
        }

        if(currB < 0) return false;

        // fill escadinha A
        for(int i = n-1; i >= 0; i--){
            int changed = 0;
            for(int j = 0; j < m and changed < 2; j++){
                if(grid[i][j] == '#') continue;            
                if(currA == 0) goto enda2;
                
                if(grid[i][j] != 'B'){
                    if(grid[i][j] == 'C') currA--;                
                    grid[i][j] = 'A';
                } 
                changed++;
                  
            }
        }

        dbg("aqui", currA, currB);
    
        enda2:    

        // fill A
        if(currA > 0){
            for(int i = n-1; i >= 0; i--){            
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == '#' or grid[i][j] == 'A' or grid[i][j] == 'B') continue;                
                    
                    if(grid[i][j] == 'C') currA--;                
                    grid[i][j] = 'A';                    
                    
                    if(currA == 0) goto filledA2;
                }
            }
        }
        
        filledA2:
        dbg("achou?", currA);

        // fill
        if(currB > 0){
            for(int i = n-1; i >= 0; i--){            
                for(int j = m-1; j >= 0; j--){
                    if(grid[i][j] == '#' or grid[i][j] == 'A' or grid[i][j] == 'B') continue;                
                    
                    if(grid[i][j] == 'C') currB--;                
                    grid[i][j] = 'B';                    
                    
                    if(currB == 0) goto filledB2;
                }
            }
        }                
    }
    filledB:
    filledB2:
    
    dbg(currA, currB);
    if(currA > 0 or currB > 0) return false;

    for(int i = n-1; i >= 0; i--){            
        for(int j = 0; j < m; j++){
            assert(grid[i][j] != 'C');
            if(grid[i][j] == '.'){
                bool hasA = false, hasB = false;
                if(j > 0){
                    if(grid[i][j-1] == 'A') hasA = true;
                    else if (grid[i][j-1] == 'B') hasB = true;
                }
                if(i < n-1){
                    if(grid[i+1][j] == 'A') hasA = true;
                    else if (grid[i+1][j] == 'B') hasB = true;
                }
                                
                if(hasA) grid[i][j] = 'A';
                else if(hasB) grid[i][j] = 'B';
                else return false;
            }
        }
    }

    dbg("passou?");
    vector<vector<int>> vst(n, vector<int>(m));


    int tot = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#') continue;
            if(!vst[i][j]){
                tot++;
                bfs(i, j, vst);
            } 
        }
    } 

    dbg(tot);


    if(tot > 2){
        return false;
    }
    return true;
}

void solution(){    
    int n;
    cin >> n;    
    m = 2*n -1;
    N = n;
    
    for(int i = 0; i < n; i++) for(int j = 0; j < m;j ++) cin >> grid[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < m;j ++) grid2[i][j] = grid[i][j];

    int cnt = 0;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(grid[i][j] == 'C') cnt++;

    if(cnt & 1){
        cout << "impossible\n";
        return;
    }

    int currA = cnt/2;
    int currB = cnt/2;
    for(int i = n; i>0; i--){
        if(i < n) for(int j = 0; j < m; j++){            
            if(grid[i][j] == 'C') currA--;
            if(grid[i][j] != '#') grid[i][j] = 'A';
        }        
        if(currA >= 0){        
            if(solve(currA, currB, i, 0)){
                for(int a = 0; a < n; a++){
                    for(int b = 0; b < m; b++) cout << grid[a][b];
                    cout << '\n';
                } 
                return;
            }
            for(int a = i - 1; a >= 0; a--) for(int j = 0; j < m;j ++) grid[a][j] = grid2[a][j];
            
            dbg(currA, currB);
                    
            if(solve(currA, currB, i, 1)){
                dbg("auioq");
                for(int a = 0; a < n; a++){
                        for(int b = 0; b < m; b++) cout << grid[a][b];
                        cout << '\n';
                    } 
                    return;
                }
            for(int a = i - 1; a >= 0; a--) for(int j = 0; j < m;j ++) grid[a][j] = grid2[a][j];
            
        }         
    }

    cout << "impossible" << endl;
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