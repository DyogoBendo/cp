#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n = 3;
    vector<vector<char>> grid(n, vector<char>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> grid[i][j];
        }        
    }

    string ans = "CCC";

    function<void(int, int, int, int, int, string)> check = [&](int x, int y, int prevx, int prevy, int cnt, string s){
        if(x < 0) return;
        if(y < 0) return;
        if(y == n) return;
        if(x == n) return;

        s += grid[x][y];
        cnt++;
        if(cnt == 3){
            ans = min(ans, s);
            return;
        }

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if(i == 0 && j == 0) continue;
                if(i + x == prevx && j + y == prevy) continue;

                check(i+x, j+y, x, y, cnt, s);
            }            
        }

    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            check(i, j, -1, -1, 0, "");      
        }
        
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}