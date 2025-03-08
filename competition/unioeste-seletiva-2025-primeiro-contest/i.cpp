#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int n, m;
int mov[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(vector<vector<vector<int>>> &dp, vector<vector<char>> &board, int p, int x, int y){
    if(dp[p][x][y]) return;

    dp[p][x][y] = 1;
    int prox_x = mov[p][0] + x;
    int prox_y = mov[p][1] + y;    
    if(prox_x >= n || prox_x < 0 || prox_y >= m || prox_y < 0 || board[prox_x][prox_y] == '#'){
        p = (p + 1) % 4;
        dfs(dp, board, p, x, y);        
    } else{
        dfs(dp, board, p, prox_x, prox_y);
    }
}

void solve(){
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    int startx, starty, p;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if(c == 'U'){
                startx = i;
                starty = j;
                p = 0;
            } else if(c == 'L'){
                startx = i;
                starty = j;
                p = 1;
            } else if(c == 'D'){
                startx = i;
                starty = j;
                p = 2;
            } else if(c == 'R'){
                startx = i;
                starty = j;
                p = 3;
            }
            board[i][j] = c;
        }        
    }    
    
    vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(m)));
    dfs(dp, board, p, startx, starty);

    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                visited[j][k] = max(visited[j][k], dp[i][j][k]);
            }
            
        }
        
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += visited[i][j];
        }
        
    }
    
    cout << ans << endl;
}

signed main(){
    flash;
    int t = 1;
    // cin >> t;

    while(t--) solve();
}