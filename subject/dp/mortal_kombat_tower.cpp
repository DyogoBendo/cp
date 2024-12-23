#include <bits/stdc++.h>

using namespace std;

const int SIZE = 2e5 + 1;
int a[SIZE], dp[SIZE][2][2];

void solve(){
    int n;
    cin >> n;    

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    dp[0][0][0] = a[0];
    dp[0][0][1] = SIZE;
    dp[0][1][0] = SIZE;
    dp[0][1][1] = SIZE;

    for (int i = 1; i < n; i++)
    {
        dp[i][0][0] = a[i] + min(dp[i - 1][1][0], dp[i - 1][1][1]);
        dp[i][0][1] = a[i] + dp[i - 1][0][0];
        dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]);
        dp[i][1][1] = dp[i - 1][1][0];
        
    }

    int ans = SIZE;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans = min(dp[n-1][i][j], ans);
        }
        
    }
    
    cout << ans << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t -- ) solve();
}