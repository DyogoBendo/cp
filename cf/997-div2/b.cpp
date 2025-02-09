#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++)
        {
            graph[i][j] = s[j] == '1';
        }
    }
    

    // sabemos que o 1 é menor do que todos, então a posição que ele está é quandtos caras maiores que ele existem
    vector<int>ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int p = 0;
        int expected_before = 0;
        for (int j = 0; j < i; j++)
        {
            expected_before += graph[i][j] ^ 1;
        }
        
        for (int j = i + 1; j < n; j++)
        {
            p += graph[i][j];
        }
        p = n - 1 - p - expected_before;
        ans[p] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
}