#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    char chuva[500][500];

    queue<pair<int, int>> agua;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> chuva[i][j];
            if(chuva[i][j] == 'o') agua.push({i, j});
        }        
    }

    while(!agua.empty()){
        int a = agua.front().first;
        int b = agua.front().second;
        agua.pop();

        if(a < n - 1){
            if(chuva[a + 1][b] == '.'){
                chuva[a + 1][b] = 'o';
                agua.push({a + 1, b});
            }
            if(b < m - 1){
                if(chuva[a][b + 1] == '.' && chuva[a + 1][b] == '#'){
                    chuva[a][b + 1] = 'o';
                    agua.push({a, b + 1});
                }
            }
            if(b > 0){
                if(chuva[a][b - 1] == '.' && chuva[a + 1][b] == '#'){
                    chuva[a][b - 1] = 'o';
                    agua.push({a, b - 1});
                }
            }
        }        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << chuva[i][j];
        }
        cout << endl;
        
    }
    
    
}