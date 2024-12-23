#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int mx = -1;
    int mn = 1e3 + 10;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mx = max(x, mx);
        mn = min(x, mn);
    }

    int ans = (mx - mn) * (n - 1);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}