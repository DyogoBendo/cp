#include <bits/stdc++.h>

using namespace std;
int grid[500][500];

int check_first(int n, int m){
    int superior_color = grid[n - 1][m - 1];
    int lowest_first_column = -1;

    for (int i = n - 1; i > 0; i--)
    {
        if(grid[i][0] == superior_color){
            lowest_first_column = i;
            break;
        }
    }

    if(lowest_first_column == -1) return 0;
    
    for (int j = 1; j < m; j++)
    {
        if(grid[0][j] == superior_color) return 1;        
    }
            

    return 0;
    
}

int check_second(int n, int m){
    int inferior_color = grid[0][0];
    int lowest_first_column = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if(grid[i][m - 1] == inferior_color){
            lowest_first_column = i;
            break;
        }
    }

    if(lowest_first_column == -1) return 0;

    for (int j = 0; j < m - 1; j++)
    {
        if(grid[n - 1][j] == inferior_color) return 1;        
    }
    
    return 0;
}


void solve(){
    int n, m;
    cin >> n >> m;

    char cse, cid;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            grid[i][j] = c == 'W';
        }
        
    }

    int possible = grid[n - 1][m - 1] == grid[0][0];
    possible = max({possible, check_first(n, m), check_second(n, m)});
    
    string ans = possible ? "YES" : "NO";
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}