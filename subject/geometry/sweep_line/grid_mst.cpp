#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

const int S = 1e3;

int grid[S][S];
int visited[S][S];
int bst[S][S];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

signed main(){
    darvem;

    int n;
    cin >> n;

    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
        sx = x, sy = y;
    }
    for(int i = 0; i < S; i++) for(int j = 0; j < S; j++)bst[i][j] = 1e9;


    priority_queue<tuple<int, int, int>> pq;    
    pq.push({0, sx, sy});
    bst[sx][sy] = 0;

    int ans = 0;
    while(!pq.empty()){
        auto [dst, x, y] = pq.top(); pq.pop();
        dst = -dst;                

        if(bst[x][y] != dst) continue;

        if(grid[x][y]){
            bst[x][y] = grid[x][y] = 0;
            ans += dst;
            pq.push({0, x, y});            
            continue;
        } 
                
        for(int i = 0; i < 4; i++){
            int x2 = dx[i] + x, y2 = dy[i] + y;
            if((x2 >=0 && x2 < S && y2 >= 0 && y2 < S) && (dst+1 < bst[x2][y2])){
                bst[x2][y2] = dst+1;
                pq.push({-(dst+1), x2, y2});
            }
        }
    }
    
    cout << ans << endl;
}