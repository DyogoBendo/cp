#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char animal[] = {'F', 'R'};

signed main(){
    darvem;

    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<int>> visited(h, vector<int>(w));

    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> grid[i][j];

    queue<tuple<int, int, int>> p, q;

    p.push({0, 0, 1});

    int ans = 0;
    int curr = grid[0][0] == 'R';

    while(!(p.empty() && q.empty())){
        if(p.empty()){            
            swap(p, q);                        
            curr ^= 1;
        }
        auto [x, y, d] = p.front(); p.pop();
        if(visited[x][y]) continue;        
        visited[x][y] = 1;        
        ans = max(ans, d);

        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b= y + dy[i];

            if(a < 0 or b < 0 or a == h or b == w) continue;
            
            if(grid[a][b] == animal[curr]) p.push({a, b, d});
            else if(grid[a][b] != '.') q.push({a, b, d+1});
        }
    }

    cout << ans << endl;
}