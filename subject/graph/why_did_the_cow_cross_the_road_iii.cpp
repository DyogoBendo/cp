#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int grid[100][100];
int visited[100][100];
int road[100][100][4];
int ans[10000];
int cnt;
int n, k, r;

int dfs(int i, int j){    
    if(visited[i][j]) return 0;    
    visited[i][j] = cnt;
    int c = grid[i][j];

    if(i > 0){
        if(!road[i][j][0]) c += dfs(i - 1, j);
    }
    if(i < n - 1){
        if(!road[i][j][1]) c += dfs(i + 1, j);
    }
    if(j > 0){
        if(!road[i][j][2]) c += dfs(i, j - 1);
    }
    if(j < n - 1){
        if(!road[i][j][3]) c += dfs(i, j + 1);
    }

    return c;
}

int main(){
    setIO("countcross");
    cin >> n >> k >> r;

    for (int i = 0; i < r; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a --; b--; c--; d--;

        int p1;
        int p2;
        if(a > c){
            p1 = 0;
            p2 = 1;
        }else if(a < c){
            p1 = 1;
            p2 = 0;
        } else if(b > d){
            p1 = 2;
            p2 = 3;
        } else{
            p1 = 3;
            p2 = 2;
        }        

        road[a][b][p1] = 1;
        road[c][d][p2] = 1; 
    }


    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a --;
        b -- ;
        grid[a][b] = 1;
    }    


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] && !visited[i][j]){
                cnt ++;
                ans[cnt - 1] = dfs(i, j);
            }
        }
        
    }
    
    
    int sol = 0;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            sol += ans[i] * ans[j];
        }
        
    }
    
    cout << sol << endl;
}