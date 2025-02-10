// https://codeforces.com/contest/1360/problem/E
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = s[j] - '0';
        }        
    }

    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == 0) continue; // 0 não impacta na resposta final

            // o proximo valor da linha ou coluna precisa ser 1 ou ter chegado em uma borda

            if(i == n-1 || j == n - 1) continue;
            if(grid[i + 1][j] == 1 || grid[i][j + 1] == 1) continue;
            possible = false;
        }
        
    }
    
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}