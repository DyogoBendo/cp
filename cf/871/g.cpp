#include <bits/stdc++.h>

using namespace std;

long long dp[2050][2050] = {0};
long long ans[2050 * 2050] = {0};

void solve(){
    long long k = 0;
    for (int i = 1; i < 2050; i++)
    {
        for (int j = 1; j < i; j++)
        {                    
            k ++;            
            dp[i - j + 1][j] = dp[i - j + 1][j - 1] + dp[i - j][j] - dp[i - j][j - 1] + (k * k);
            ans[k] = dp[i - j + 1][j];
        }        
    }    
}

int main(){
    solve();
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cout << ans[n] << endl;
    }
}