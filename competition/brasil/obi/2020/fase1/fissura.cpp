#include <bits/stdc++.h>

using namespace std;

char terreno[500][500];
int n;
char f;
void bfs(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= n) return;
    if( terreno[i][j] != '*' && terreno[i][j] <= f ){
        terreno[i][j] = '*';
        bfs(i - 1, j);
        bfs(i + 1, j);
        bfs(i, j - 1);
        bfs(i, j + 1);
    }
}

int main(){
    cin >> n >> f;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> terreno[i][j];
        }        
    }    

    bfs(0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << terreno[i][j];
        }
        cout << endl;
        
    }
    
}