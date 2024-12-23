#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE =1e6 + 1;
int dp[MAX_VALUE];

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> m(n);

    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        dp[m[i]] = 1;
    }        
    
    for (int i = 0; i <= x; i++)
    {
        if(dp[i] == 0) continue;
        for (int j = 0; j < n; j++)
        {
            int p = m[j] + i;                        
            if(p <= x){
                if(dp[p] == 0) dp[p] = dp[i] + 1;
                dp[p] = min(dp[p], dp[i] + 1);
            }
        }
        
    }

    if(dp[x] == 0) cout << -1 << endl;
    else cout << dp[x] << endl;

}