#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    vector<int> groups(n*m + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            groups[v[i][j]] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i > 0 && v[i - 1][j] == v[i][j]){
                groups[v[i][j]] = 2;
            } 
            if(j > 0 && v[i][j - 1] == v[i][j]){
                groups[v[i][j]] = 2;
            } 
        }
        
    }
    
    int ans = 0;
    int mx = -1;
    int cnt = 0;

    for(int x : groups){
        if(x) cnt ++;
        ans += x;
        mx = max(mx, x);
    }
    ans -= mx;
    if(cnt == 1) ans = 0;
    
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}