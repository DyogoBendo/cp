#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n+1, n+1);    
    dp[n] = 0;
    
    for (int i = n-1; i >=0; i--)
    {
        if(v[i] + i < n) dp[i] = dp[v[i]+i + 1];
        dp[i] = min(dp[i], dp[i+1] + 1);
    }
    
    cout << dp[0] << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}