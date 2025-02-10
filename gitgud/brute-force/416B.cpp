// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> time(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int t;
            cin >> t;
            if(i == 0 && j == 0){
                time[i][j] = t;
            } else{
                if(i == 0){
                    time[i][j] = time[i][j-1] + t;
                } else{
                    if(j == 0){
                        time[i][j] = time[i - 1][j] + t;
                    } else{
                        time[i][j] = max(time[i - 1][j], time[i][j - 1]) + t;
                    }
                }
            }
        }
        cout << time[i][n - 1] << " ";
    }
    cout << endl;
}