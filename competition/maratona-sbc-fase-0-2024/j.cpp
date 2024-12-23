#include <bits/stdc++.h>

using namespace std;

#define S 500
int n, m;
int k, l;
int board[S][S];

int valid(int i, int j){
    if(i < 0) return 0;
    if(i >= n) return 0;
    if(j < 0) return 0;
    if(j >= m) return 0;
    return board[i][j];
}

int check(int i, int j){
    int total = 0;
    int x1 = i - k;
    int y1 = j - l;
    total += valid(x1, y1);

    int x2 = i + k;
    int y2 = j - l;
    total += valid(x2, y2);

    int x3 = i - k;
    int y3 = j + l;
    total += valid(x3, y3);

    int x4 = i + k;
    int y4 = j + l;
    total += valid(x4, y4);

    int x5 = i - l;
    int y5 = j - k;
    total += valid(x5, y5);

    int x6 = i - l;
    int y6 = j + k;
    total += valid(x6, y6);

    int x7 = i + l;
    int y7 = j - k;
    total += valid(x7, y7);

    int x8 = i + l;
    int y8 = j + k;
    total += valid(x8, y8);    

    return total;
}



int main(){
    cin >> n >> m;
    cin >> k >> l;
    k--;
    l --;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char b;
            cin >> b;
            board[i][j] = b == '*';
        }
        
    }
    

    int ans = 0;
    int cx = -1, cy = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!board[i][j]){
                if(check(i, j) > ans || cx == -1){
                    ans = check(i, j);
                    cx = i;
                    cy = j;
                }
            }
        }
        
    }
    
    cout << cx + 1 << " " << cy + 1 << endl;
}