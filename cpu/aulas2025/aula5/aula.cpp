#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    vector<int> soma_prefixos(n+1);

    for (int i = 1; i <= n; i++)
    {
       soma_prefixos[i] = soma_prefixos[i-1] + v[i-1];
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << soma_prefixos[r+1] - soma_prefixos[l] << endl;
    }  
}