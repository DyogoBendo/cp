// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> v(2, vector<int>(n));
    vector<vector<vector<int>>> visited(2, vector<vector<int>>(n, vector<int>(2, 0)));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c == '>') v[i][j] = 1;
            else v[i][j] = -1;
        }
    }

    auto dfs = [&](int row, int column, int state, auto &&dfs) -> void{
        if(row >= 2 || row <0 || column >= n || column < 0) return;
        if(visited[row][column][state]) return;
        visited[row][column][state] = 1;
        if(state == 0){
            dfs(row + 1, column, 1, dfs);
            dfs(row - 1, column, 1, dfs);
            dfs(row, column + 1, 1, dfs);
            dfs(row, column - 1, 1, dfs);
        } else{
            dfs(row, column + v[row][column], 0, dfs);
        }
    };

    dfs(0, 0, 0, dfs);

    if(visited[1][n-1][0] || visited[1][n-1][1]){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

}

int main() {
    int t;
    cin >> t;

    while(t--) solve();
}