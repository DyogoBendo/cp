#include <bits/stdc++.h>

using namespace std;

int tabuleiro[6][6];

int l, c, n, ans;
void solve(int i, int j, int curr){    
    ans = max(ans, curr);
    if(i == l) return;
    int pi = i, pj = j + 1;
    if(j == c - 1){
        pi = i + 1;
        pj = 0;
    }
    solve(pi, pj, curr);
    bool left = false, up = false, right = false, down = false;

    if(j == 0 || tabuleiro[i][j - 1] != -1){
        left = true;
    }
    if(j == c - 1 || tabuleiro[i][j + 1] != -1){
        right = true;
    }

    if(i == 0 || tabuleiro[i - 1][j] != -1){
        up = true;
    }
    if(i == l - 1 || tabuleiro[i + 1][j] != -1){
        down = true;
    }

    bool black = false;

    if(j > 0 && tabuleiro[i][j - 1] == 1){
        black = true;
    }
    if(j < c - 1 && tabuleiro[i][j + 1] == 1){
        black = true;
    }
    if(i > 0 && tabuleiro[i - 1][j] == 1){
        black = true;
    }
    if(i < l - 1 && tabuleiro[i + 1][j] == 1){
        black = true;
    }

    bool free = false;
    if(tabuleiro[i][j] == 0) free = true;

    if(black && left && right && up && down && free){
        tabuleiro[i][j] = -1;
        solve(pi, pj, curr + 1);
        tabuleiro[i][j] = 0;
    }        

}

int main(){
    cin >> l >> c >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tabuleiro[a][b] = 1;
    }

    solve(0, 0, 0);

    cout << ans << endl; 

}