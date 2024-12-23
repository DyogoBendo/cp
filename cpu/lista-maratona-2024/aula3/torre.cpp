#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
        
    }

    vector<int> rs(n);
    vector<int> cs(n);

    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += v[i][j];
        }
        rs[i] = s;
    }
    
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += v[j][i];
        }
        cs[i] = s;
    }
       
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, cs[j] + rs[i] - 2 *v[i][j]);
        }
        
    }
    
    cout << ans << endl;
}