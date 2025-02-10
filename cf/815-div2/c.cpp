#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    int cnt = 0;

    vector<vector<int>> matrix (n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = s[j] - '0';
            if(matrix[i][j]) cnt ++;
        }
        
    }

    int k = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int r = matrix[i][j] + matrix[i + 1][j] + matrix[i][j + 1] + matrix[i + 1][j + 1];

            k = min(k, int(r > 2));
        }
        
    }
    

    if(cnt == n * m){
        cout << cnt - 2 << endl;
    } else{
        if(k) cout << cnt - 1 << endl;
        else cout << cnt << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}