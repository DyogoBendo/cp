#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
const int MAX = 1e9;

int h[MAXN];
int dp[MAXN];

int main(){
    int n;
    cin >> n;    
    for (int i = 0; i < n; i++)
    {
        cin >> h[i + 1];        
        dp[i + 1] = MAX;
    }

    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i <= n - 1) dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        if(i <= n - 2) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }

    cout << dp[n] << endl;        
}