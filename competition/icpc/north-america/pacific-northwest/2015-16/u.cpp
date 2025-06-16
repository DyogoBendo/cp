#include <bits/stdc++.h>

using namespace std;

#define int long long

int mv[] = {1, 0, -1};

int w, h, b;
vector<vector<int>> solve(vector<vector<int>> &v){
    vector<vector<int>> u(h, vector<int>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int x = 0;

            for (int d = 0; d < 3; d++)
            {
                for (int k = 0; k < 3; k++)
                {
                    int i2 = (i + mv[d] + h) % h;
                    int j2 = (j + mv[k] + w) % w;

                    x += v[i2][j2];
                }
                u[i][j] = x;
            }            
        }
        
    }
    
    return u;
}

signed main(){
    cin >> w >> h >> b;

    vector<vector<int>> v(h, vector<int>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> v[i][j];
        }        
    }

    while(b--){
        v = solve(v);
    }

    set<int> ans;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans.insert(v[i][j]);
        }
        
    }

    cout << ans.size() << endl;
}