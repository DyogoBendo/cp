#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main(){
    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    vector<int> dpc(m + 1, 0);
    vector<int> dpp(m + 1, 0);

    if(v[0] == 0){
        for (int i = 1; i <= m ; i++)
        {
            dpp[i] = 1;            
        }        
    } else{
        dpp[v[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int x = v[i];
        if(x == 0){
            for (int j = 1; j <= m; j++)
            {
                dpc[j] = dpp[j];
                if(j > 1) dpc[j] += dpp[j - 1];
                if(j < m) dpc[j] += dpp[j + 1];                  

                dpc[j] %= MOD;
            }                                       
        } else{
            dpc[x] = dpp[x];
            if(x > 1) dpc[x] += dpp[x - 1];
            if(x < m) dpc[x] += dpp[x + 1];
            
            dpc[x] %= MOD;
        }

        for (int i = 1; i <= m; i++)
        {
            dpp[i] = dpc[i];
            dpc[i] = 0;
            
        }        
                
    }
    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        ans += dpp[i];
        ans %=MOD;
    }
    cout << ans << endl;
    
}