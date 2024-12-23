#include <bits/stdc++.h>

using namespace std;



int main(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> forest(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
            char c;
            cin >> c;

            if(c == '*') forest[i][j] = 1;
        }
        
    }
    

    vector<vector<int>> sum2d(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum2d[i][j] = sum2d[i - 1][j] + sum2d[i][j - 1] - sum2d[i - 1][j - 1] + forest[i - 1][j - 1];
        }
        
    }    
    for (int i = 0; i < q; i++)
    {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = sum2d[x2][y2] - sum2d[x2][y1 - 1] - sum2d[x1 - 1][y2] + sum2d[x1 - 1][y1 - 1];

        cout << ans << endl;
    }
    
}