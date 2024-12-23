#include <bits/stdc++.h>

using namespace std;

int main(){
    int movesX[8][8][8];
    int movesY[8][8][8];

    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            int x1, x2, x3, x4;
            int y1, y2, y3, y4;
            x1 = i - 2;
            x2 = i - 1;
            x3 = i + 1;
            x4 = i + 2;

            y1 = j - 2;
            y2 = j - 1;
            y3 = j + 1;
            y4 = j + 2;
            
            movesX[i][j][0] = x1;
            movesY[i][j][0] = y2;

            movesX[i][j][1] = x1;
            movesY[i][j][1] = y3;

            movesX[i][j][2] = x2;
            movesY[i][j][2] = y1;

            movesX[i][j][3] = x2;
            movesY[i][j][3] = y4;

            movesX[i][j][4] = x3;
            movesY[i][j][4] = y1;

            movesX[i][j][5] = x3;
            movesY[i][j][5] = y4;

            movesX[i][j][6] = x4;
            movesY[i][j][6] = y2;

            movesX[i][j][7] = x4;
            movesY[i][j][7] = y3;
        }
        
    }
    

    int t;
    cin >> t;


    while (t)
    {
        t --;

        char start[3];
        char end[3];
        cin >> start >> end;        

        int board[8][8];

        int sx = start[0] - 'a';
        int sy = start[1] - '1';
        int ex = end[0] - 'a';
        int ey = end[1] - '1';        

        int visited[8][8] = {0};        
        int distance[8][8] = {0};

        visited[sx][sy] = 1;        

        queue<pair<int, int>> q;
        q.push(make_pair(sx, sy));

        while(!q.empty()){
            auto current = q.front();
            q.pop();
            
            int i = current.first, j = current.second;

            for (size_t k = 0; k < 8; k++)
            {
                int nextI = movesX[i][j][k];
                int nextJ = movesY[i][j][k];

                if(nextI >= 0 && nextI < 8 && nextJ >= 0 && nextJ < 8){
                    if(!visited[nextI][nextJ]){
                        visited[nextI][nextJ] = 1;
                        distance[nextI][nextJ] = distance[i][j] + 1;
                        q.push(make_pair(nextI, nextJ));
                    }
                }
            }            
        }

        cout << distance[ex][ey] << endl;
    }
    
}