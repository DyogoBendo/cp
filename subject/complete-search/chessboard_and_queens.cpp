#include <bits/stdc++.h>

using namespace std;

int board[8][8];
int total = 0;

void m(int value, int x, int y){

    // marcar mesma coluna

    for (int i = x; i < 8; i++)
    {
        if(board[i][y] == -1) continue;
        board[i][y] += value;
    }

    // marcar mesma diagonal principal

    for (int i = x, j = y; i < 8 && j < 8; i++, j++)
    {
        if(board[i][j] == -1) continue;
        board[i][j] += value;
    }
    
    // marcar diagonal secundaria

    for (int i = x, j = y; i < 8 && j >= 0 ; i++, j--)
    {
        if(board[i][j] == -1) continue;
        board[i][j] += value;
    }
    
    
    board[x][y] = 1;


}

void solve(int line){
    if(line == 8){
        total  ++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if(board[line][i] == 1){
            m(1, line, i);
            solve(line + 1);
            m(-1, line, i);
        }
    }
    
}



int main(){

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c;
            cin >> c;
            if(c == '*') board[i][j] = -1;
            else board[i][j] = 1;
        }
        
    }

    solve(0);

    cout << total << endl;
}