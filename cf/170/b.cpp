#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
ll dp[MAX];

int main(){
    int t, k;
    cin >> t;    

    dp[0] = 1;

    for (int i = 1; i <= MAX; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 1];
        dp[i] %= MOD;
    }

    for (int i = 0; i < t; i++)
    {
        cin >> k;
    }
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        cout << dp[k] << endl;
    }
    
}