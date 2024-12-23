#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, m;

    cin >> n >> m;

    vector<vector<int>> cards(m, vector<int>(n));    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;            
            cin >> x;            
            cards[j][i] = x;            
        }        
    }

    for (int i = 0; i < m; i++)
    {
        sort(cards[i].begin(), cards[i].end());
    }
    
    
    int result = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result += cards[i][j] * (2 * j - n + 1);
        }
        
    }
    
    
    cout << result << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}