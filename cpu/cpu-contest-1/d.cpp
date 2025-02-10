// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, d;
    cin >> n >> d;

    vector<int> v(n);
    vector<int> dp(n);

    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + i;
    }

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int i = 0, j = 0;
    int ans = 0;

    while(i < n){
        while( j < n && v[j] - v[i] <= d){
            j ++;
        }
        int dst = j - i - 2;
        if(dst > 0) ans += dp[dst];
        i++;
    }

    cout << ans << endl;

}