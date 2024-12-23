#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, a, p;
bool grid[1000][1000];
bool visited[1000][1000];

void dfs(int i, int j){
    if(visited[i][j]) return;
    visited[i][j] = true;
    a ++;

    if(i > 0){
        if(grid[i - 1][j]) dfs(i - 1, j);
        else p ++;
    } else{
        p ++;
    }

    if(i < n - 1){
        if(grid[i + 1][j]) dfs(i + 1, j);
        else p ++;
    } else{
        p ++;
    }

    if(j > 0){
        if(grid[i][j - 1]) dfs(i, j - 1);
        else p ++;
    } else{
        p ++;
    }

    if(j < n - 1){
        if(grid[i][j + 1]) dfs(i, j + 1);
        else p ++;
    } else{
        p ++;
    }

}

int main(){
    setIO("perimeter");
    cin >> n;    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c == '#';
        }
        
    }

    int max_a = 0, max_p = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] && !visited[i][j]){
                a = 0;
                p = 0;

                dfs(i, j);

                if(a > max_a){
                    max_a = a;
                    max_p = p;
                } else if(a == max_a){
                    max_p = min(p, max_p);
                }
            }
        }
        
    }

    cout << max_a << " " << max_p << endl;   
    
}