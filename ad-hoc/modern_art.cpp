#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<int> someone_depends(10,0);
    vector<int> appears(10,0);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }

    int diff = 0;

    for (int k = 1; k <= 9; k++)
    {
        // vamos verificar qual a área de cada uma das cores. 

        int l = n, b = -1;
        int r = -1, t = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] == k){
                    l = min(j, l); //
                    b = max(b, i);
                    t = min(i, t);
                    r = max(j, r);
                }
            }
            
        }


        if(r != -1){
            appears[k - 1] = 1;
            for (int i = t; i <= b; i++)
            {
                for (int j = l; j <= r; j++)
                {
                    if(grid[i][j] != k){
                        someone_depends[grid[i][j] - 1] = 1;
                    }
                }
                
            }
        }

        
    }

    int ans =0;

    for (int i = 0; i <= 9; i++)
    {
        if(!someone_depends[i] && appears[i]) ans ++;
    }
    
    cout << ans << endl;
}