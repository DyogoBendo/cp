#include <bits/stdc++.h>

using namespace std;

int v[51][51];

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

    int ans = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            for (int c = 0; c < m; c++)
            {
                for (int d = c; d < m; d++)
                {
                    int conta = 0;
                    int total = (b - a + 1) * (d - c + 1);
                    for (int e = a; e <= b; e++)
                    {
                        for (int f = c; f <= d; f++)
                        {
                            conta += v[e][f];
                        }
                        
                    }
                    
                    if(conta == 0 || conta == total) ans ++;
                }
                
            }
            
        }
        
    }
    
    cout << ans << endl;
    
}