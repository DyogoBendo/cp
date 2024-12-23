#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long row, column;
        cin >> row >> column;

        if(row > column){
            if(row % 2 == 0) cout << row * row - column + 1;
            else cout << (row - 1) * (row - 1) + column;
        } else{
            if(column % 2 == 1) cout << column * column - row + 1;
            else cout << (column - 1) * (column - 1) + row;
        }
        cout << endl;
    }
    
    
}