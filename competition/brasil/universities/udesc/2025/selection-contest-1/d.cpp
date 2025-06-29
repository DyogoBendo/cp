#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

signed main(){

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int>> v(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <=m; j++){
            cin >> v[i][j];
        }
    }
    
    auto solve = [&](int x, int y){        
        vector<vector<bool>> visited;
        function<bool(int, int, int)> dfs = [&] (int a, int b, int cant){            
            if(a == n && b == m) return true;
            visited[a][b] = true;
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + a;
                int y = dy[i] + b;
    
                if(x == 0 or x > n or y == 0 or y > m) continue;
                if(v[x][y] & cant) continue;
                if(visited[x][y]) continue;
                if(dfs(x, y, cant)) return true;
            }
            return false;        
        };
        int uneeded = 0, ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            visited = vector<vector<bool>>(n+1, vector<bool>(m+1));
            if(dfs(x, y, uneeded | (1 << i))) uneeded |= (1 << i);
            else ans |= (1 << i);
        }
        return ans;
    };

    cout << solve(1, 1) << " " << solve(x, y) << endl;
}