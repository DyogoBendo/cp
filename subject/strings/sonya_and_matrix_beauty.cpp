#include <bits/stdc++.h>

using namespace std;

int matriz[250][26];
int main(){
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            matriz[i][c - 'a'] ++;
        }
        
    }


    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int atual[26];
        for (int c = 0; c < 26; c++)
        {
            atual[c] = matriz[i][c];
        }
        
        for (int j = i; j < n; j++)
        {                            
                for (int c = 0; c < 26; c++)
                {
                    atual[c] = min(atual[c], matriz[j][c]);
                }                
            
                long long qPar = 0;
                long long qImpar = 0;
                int temImpar = -1;
                
                for (int c = 0; c < 26; c++)
                {                    
                    if(atual[c] % 2 == 1) temImpar = 1;
                    qPar += atual[c] / 2 * 2;                                        
                }            
                
                qImpar += temImpar;

                long long q = max(qImpar, qPar);
                cout << "possibilidades: " << (q * m) - ((q - 1) * q) / 2 << endl;
                ans  += (q * m) - ((q - 1) * q) / 2;    
        }
        
    }

    cout << ans << endl;
    
    
}