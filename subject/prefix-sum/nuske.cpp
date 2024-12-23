#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            grid[i][j] = (x == '1');
        }
        
    }


    vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            if(grid[i][j] == 1){
                if(grid[i - 1][j] && grid[i][j - 1]){
                    prefix_sum[i][j]--;
                } 
                if(!grid[i - 1][j] && !grid[i][j - 1]){
                    prefix_sum[i][j] ++;
                }
            }
        }       
    }

    vector<vector<int>> row_components(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> column_components(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            row_components[i][j] = row_components[i][j - 1];
            column_components[i][j] = column_components[i - 1][j];
            if(grid[i][j]){
                row_components[i][j] += !grid[i][j - 1];
                column_components[i][j] += !grid[i - 1][j];
            }
        }
        
    }
    
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int ans = grid[a][b];

        ans += row_components[a][d] - row_components[a][b];
        ans += column_components[c][b] - column_components[a][b];

        ans += prefix_sum[c][d] - prefix_sum[c][b] - prefix_sum[a][d] + prefix_sum[a][b];
        cout << ans << endl;
    }
    
    
}