#include <bits/stdc++.h>

using namespace std;

int INF = 1e8;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> vp;

    for (int i = 0; i < n; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        vp.push_back({x1, x2});
    }

    sort(vp.begin(), vp.end());

    vector<int> dp(n + 1, INF);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x = -vp[i].second;
        int p = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        dp[p] = x;
        ans = max(ans, p);
    }

    cout << ans + 1 << endl;
}