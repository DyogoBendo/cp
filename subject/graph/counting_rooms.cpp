#include <bits/stdc++.h>

using namespace std;

int n, m;
void dfs(int i, int j, vector<vector<bool>> &ma, vector<vector<bool>> &v){
    if(v[i][j]) return;

    if(!ma[i][j]) return;

    v[i][j] = true;
    if(i > 0) dfs(i - 1, j, ma, v);
    if(i < n - 1) dfs(i + 1, j, ma, v);
    if(j > 0) dfs(i, j - 1, ma, v);
    if(j < m - 1) dfs(i, j + 1, ma, v);
}

int main(){
    cin >> n >> m;

    vector<vector<bool>> matrix(n, vector<bool>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            matrix[i][j] = c == '.';
        }
        
    }


    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matrix[i][j] && !visited[i][j]){
                ans ++;
                dfs(i, j, matrix, visited);
            }
        }
        
    }
    
    cout << ans << endl;
}