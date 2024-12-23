#include <bits/stdc++.h>

using namespace std;

long long dp[1 << 19][19];

long long solve (long long mask, int last, int count, int n, int m, int a[19], int b[19][19]){
    if(count == m){
        return 0;
    }

    if(dp[mask][last] != - 1) return dp[mask][last];

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(!(mask & 1 << i)){
            ans = max(ans, solve(mask | (1 << i), i, count + 1, n, m, a, b) + a[i] + b[last][i]);
        }
    }
    dp[mask][last] = ans;

    return ans;
    
}

int main(){
    int n, m, k;

    cin >> n >>m >>k;
    int satisfaction[19] = {0};
    int bonus[19][19] = {0};
    

    for (int i = 0; i < n; i++) cin >> satisfaction[i];    
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a --;
        b --;
        bonus[a][b] = c;
    }
    

    memset(dp, -1, sizeof dp);
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, solve(1 << i, i, 1, n, m, satisfaction, bonus) + satisfaction[i]);
    }
    
    cout << ans << endl;
}