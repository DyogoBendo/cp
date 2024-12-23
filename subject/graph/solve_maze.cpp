#include <bits/stdc++.h>

using namespace std;

char grid[50][50];
int visited[50][50];
int n, m;


int dfs(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m) return 0;
    if(visited[i][j]) return 0;
    if(grid[i][j] == '#') return 0;

    visited[i][j] = 1;

    int c = grid[i][j] == 'G';

    c += dfs(i - 1, j);
    c += dfs(i + 1, j);
    c += dfs(i, j - 1);
    c += dfs(i, j + 1);

    return c;
}

void solve(){
    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
        
    }
    
    int good = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {            
            if(grid[i][j] == 'B'){
                if(i > 0){
                    if(grid[i - 1][j] == 'G'){
                        cout << "NO" << endl;
                        return;
                    } else if(grid[i - 1][j] == '.') grid[i - 1][j] = '#';
                } 

                if(i < n - 1){
                    if(grid[i + 1][j] == 'G'){
                        cout << "NO" << endl;
                        return;
                    } else if(grid[i + 1][j] == '.') grid[i + 1][j] = '#';
                } 

                if(j > 0){
                    if(grid[i][j - 1] == 'G'){
                        cout << "NO" << endl;
                        return;
                    } else if(grid[i][j - 1] == '.') grid[i][j - 1] = '#';
                } 

                if(j < m - 1){
                    if(grid[i][j + 1] == 'G'){
                        cout << "NO" << endl;
                        return;
                    } else if(grid[i][j + 1] == '.') grid[i][j + 1] = '#';
                }            
            }
            else if(grid[i][j] == 'G') good ++;
        }
        
    }    

    if(dfs(n - 1, m - 1) != good) cout << "NO" << endl;
    else cout << "YES" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}