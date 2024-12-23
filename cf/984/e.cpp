#include <bits/stdc++.h>

using namespace std;


signed main(){
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> paises(n, vector<int>(k));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> paises[i][j];
        }
        
    }

    vector<int> valores;
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            paises[j][i] |= paises[j - 1][i];
            valores.push_back(paises[j][i]);
        }        
    }
    
    sort(valores.)

}