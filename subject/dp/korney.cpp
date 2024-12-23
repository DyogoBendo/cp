#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(512, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        for (int j = 0; j < 512; j++)
        {
            if(dp[j] != -1 && dp[j] < x){
                int y = x ^ j;
                if(x < dp[y] || dp[y] == -1)  dp[y] = x;
            }
        }        
    }

    int ans = 0;
    
    for (int i = 0; i < 512; i++)
    {
        if(dp[i] != -1) ans ++;
    }
    cout << ans << endl;
    for (int i = 0; i < 512; i++)
    {
        if(dp[i] != -1) cout << i << " ";
    }

    cout << endl;
    
    
}