#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<map<int, int>> m(n); // m[i][g] -> tamanho do maior subarray que termina na posição I, e que tem GCD g

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[i][v[i]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (auto [g, sz] : m[i-1]) // tentamos expandir com os valores possíveis do anterior, só podemos ter no máximo log distintos
        {
            int g2 = gcd(g, v[i]);
            m[i][g2] = max(m[i][g2], sz + 1);
        }        
    }
    
    vector<int> ans(n+1);

    for (int i = 0; i < n; i++)
    {
        for (auto [g, sz] : m[i])
        {
            ans[sz] = max(ans[sz], g);
        }        
    }
    for (int i = n; i >0; i--)
    {        
        ans[i-1] = max(ans[i], ans[i-1]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}