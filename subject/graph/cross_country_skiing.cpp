#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int grid[500][500];
int wp[500][500];
int visited[500][500];
int m, n, a, b;
void dfs(int i, int j, int k){
    if(visited[i][j]) return;
    visited[i][j] = 1;
    if(i > 0){
        if(abs( grid[i - 1][j] - grid[i][j]) <= k) dfs(i - 1, j, k);
    }
    if(i < m - 1){
        if(abs( grid[i + 1][j] - grid[i][j]) <= k) dfs(i + 1, j, k);
    }
    if(j > 0){
        if(abs( grid[i][j - 1] - grid[i][j]) <= k) dfs(i, j - 1, k);
    }
    if(j < n - 1){
        if(abs( grid[i][j + 1] - grid[i][j]) <= k) dfs(i, j + 1, k);
    }
}

int check(int k){    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
        
    }
    
    dfs(a, b, k);

    int countA = 0;
    int countB = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if(wp[i][j]) countA ++;
            if(wp[i][j] && visited[i][j]) countB ++;
        }
        
    }

    return countA == countB;
    
}

int main(){
    setIO("ccski");

    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
        
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> wp[i][j];

            if(wp[i][j]){
                a = i;
                b = j;
            }
        }
        
    }

    int lo = 0;
    int hi = 1e9 + 1;

    while(lo < hi){        
        int mid = (hi - lo) / 2 + lo;

        if(check(mid)){
            hi = mid;
        } else{
            lo = mid + 1;
        }
    }

    cout << lo << endl;   
}