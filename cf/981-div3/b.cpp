#include <bits/stdc++.h>

using namespace std;

void solve(){
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

    int ans = 0;

    for(int i = 0; i < n; i++){
        int mn1 = 0;
        int mn2 = 0;
        for (int j = 0; i + j < n; j++)
        {
            mn1 = min(mn1, v[j][i + j]);
        }        
        for (int j = n - 1; j - i - 1 >= 0; j--)
        {
            mn2 = min(mn2, v[j][j - i - 1]);
        }
        if(mn1 < 0) ans += mn1;
        if(mn2 < 0) ans += mn2;
    }

    cout << -ans << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}