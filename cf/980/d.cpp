#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MIN = -(4e14 + 10);

int solve(int c, int s){
    if()
    return max(s + a[c], solve(b[i])
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    vector<int> psum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        psum[i + 1] = psum[i] + a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> dp(n, MIN);
    dp[0] = 0;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        dp[b[i] - 1] = max(dp[b[i] - 1], dp[i] - a[i]);
        cout << "i: " << i << " valor minimo: " << dp[i] << endl;
        dp[i] = dp[i] + psum[i + 1];
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}