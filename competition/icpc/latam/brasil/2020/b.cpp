#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int SIZE = 10;
int grid[10][10];

signed main(){
    darvem;

    int n;
    cin >> n;

    bool possible = true;
    for(int i = 0; i < n; i++){
        int d, l, c, r;
        cin >> d >> l >> r >> c;

        r--; c--;
        if(d == 0){
            if(c + l - 1 >= SIZE) possible = false;
            else for(int j = c; j <= c+l-1; j++) grid[r][j]++;
        } else{
            if(r + l - 1 >= SIZE) possible = false;
            else for(int j = r; j <= r+l-1; j++) grid[j][c]++;
        }
    }
    for(int i = 0; i < SIZE; i++) for(int j = 0; j < SIZE; j++) if(grid[i][j] > 1) possible = false;
    cout << (possible ? "Y" : "N") << endl;
}