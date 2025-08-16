#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vector<vector<int>> cost(l, vector<int>(m, -1));
    
    int tot = 0, mod = 0;
    vector<int> choice(l);
    for(int i = 0; i < l; i++){
        int mn = 1e9, md = -1;
        for(int k = 0; k < m; k++){
            int c = 0;            
            for(int j = i; j < n; j +=l){
                if(k >= v[j]) c += k - v[j];
                else c += k + (m - v[j]);
            }
            if(c < mn) mn = c, md = k;
            cost[i][k] = c;            
        }
        tot += mn;
        choice[i] = md;
        mod = (mod + md) % m;
    }

    vector<int> dp(m, 1e9);
    dp[mod] = tot;    
    for(int i = 0; i < l; i++){
        vector<int> tmp(m, 1e9);
        for(int j = 0; j < m; j++){
            if(choice[i] == j or cost[i][j] == -1) continue;
            int add = cost[i][j] - cost[i][choice[i]];            
            for(int k = 0; k < m; k++){
                int pos = (k + j - choice[i] + m) % m;
                tmp[pos] = min(dp[k] + add, tmp[pos]);                
            }            
        }
        for(int j = 0; j < m; j++){
            dp[j] = min(dp[j], tmp[j]);            
        }         
    }
    cout << dp[0] << endl;
}