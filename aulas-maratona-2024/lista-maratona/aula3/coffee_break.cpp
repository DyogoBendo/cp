#include <bits/stdc++.h>

using namespace std;

int v[400][400];
int ps[401][401];

int main(){
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
        
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + v[i - 1][j - 1];
        }
        
    }
    

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int a = 0; a < m; a++)
            {
                for (int b = a; b < m; b++)
                {
                    int elements = (j - i + 1) * (b - a + 1);
                    if(elements == ps[j + 1][b + 1] - ps[i][b + 1] - ps[j + 1][a] + ps[i][a]) ans = max(ans, elements); 
                }
                
            }
            
        }
        
    }
    
    cout << ans << endl;
       
}