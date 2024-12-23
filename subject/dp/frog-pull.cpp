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
    dp[2] = abs(h[2] - h[1]); 
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));        
    }

    cout << dp[n] << endl;        
}