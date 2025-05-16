#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
const int MOD = 1e9+7;

int add(int a, int b){
    return (0LL) + a + b % MOD;
}

int mul(int a, int b){
    return (1LL) * a * b % MOD;
}

signed main(){
    int n;
    cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 1; i <= n - 1; i++)
    {
        int x;
        cin >> x;

        tree[x].push_back(i);        
    }
    
    vector<vector<int>> dp(n, vector<int>(n+1));        

    function<void(int)> dfs = [&](int curr){                        
        dp[curr][1] = 1;
        for (int i = 0; i < tree[curr].size(); i++)
        {
            int u = tree[curr][i];
            dfs(u);                 

            if(i == 0){
                dp[curr][]
            }
            vector<int> ndp(n+1);                

            for (int i = 0; i < n+1; i++)
            {
                
            }
            
        }   
       
    };

    dfs(0);

    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            ans = add(ans, dp[j][i]);
        }
        
        cout << ans << endl;
    }
    

}