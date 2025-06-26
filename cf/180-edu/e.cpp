#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAX = 5e5 + 10;
const int INF = 1e9;
int dp[MAX];

void solve(){
    int m;
    cin >> m;

    if(dp[m] == INF) dp[m] = -1;

    cout << dp[m] << endl;
}


signed main(){
    dp[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        if(i % 2 == 0){
            dp[i] = INF;
            continue;
        } 
        dp[i] = INF;
        for (int j = 1; j * j <= i; j++)
        {
            if(i % j == 0){
                if(j > 2) dp[i] = min(dp[i], dp[j - 2] + dp[i/j]);
                if(i/j > 2) dp[i] = min(dp[i], dp[i/j - 2] + dp[j]);
            }
        }        
    }

    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}