#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char M[] = {'D', 'R', 'U', 'L'};

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    int sx, sy, ex, ey;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];

            if(grid[i][j] == 'A') sx =i, sy = j;
            if(grid[i][j] == 'B') ex = i, ey = j;
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({sx, sy, -1});

    vector<vector<int>> visited(n, vector<int>(m));
    vector<vector<int>> prev(n, vector<int>(m));


    while(!q.empty()){
        auto [x, y, mov] = q.front(); q.pop();

        if(visited[x][y]) continue;
        visited[x][y] = 1;

        prev[x][y] = mov;

        for(int i = 0; i < 4; i++){
            int a = dx[i] + x, b = dy[i] + y;

            if(a < 0 or b < 0 or a==n or b == m) continue;

            if(!visited[a][b] && grid[a][b] != '#') q.push({a, b, i});
        }        
    }

    if(!visited[ex][ey]){
        cout << "NO" << endl;
        return 0;
    }       
    cout << "YES" << endl;

    string ans;
    int curr = prev[ex][ey];    
    while(curr != -1){        
        ans += M[curr];
        ex -= dx[curr];
        ey -= dy[curr];
        curr = prev[ex][ey];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl << ans << endl;   
}