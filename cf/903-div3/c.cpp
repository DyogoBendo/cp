#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;    
    vector<vector<int>> matrix (n, vector<int> (n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            matrix[i][j] = int(c);
        }
        
    }
    
    int ans = 0;

    vector<vector<int>> checked (n, vector<int> (n, -1));

    int k = 0;
    vector<int> values;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(checked[i][j] == -1){
                checked[i][j] = k;                
                values.push_back(matrix[i][j]);
                k ++;
            }            

            checked[j][n - i - 1] = checked[i][j];            
            checked[n - j - 1][i] = checked[i][j];            

            values[checked[i][j]] = max(matrix[i][j], values[checked[i][j]]);
        }        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += values[checked[i][j]] - matrix[i][j];
        }
        
    }
    
    

    
    cout << ans << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}