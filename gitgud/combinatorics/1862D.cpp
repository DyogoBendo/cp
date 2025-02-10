#include <bits/stdc++.h>

using namespace std;

#define int long long
#define lld long double

void solve(){
    int n;
    cin >> n;

    int l = 0, r = min<int>(2e9, 2 *n);

    while(r - l > 1){
        int m = (l + r) >> 1;

        if(m * (m - 1) / 2 + m < n){
            l = m;
        } else r = m;
    }

    int y = n - r * (r - 1) / 2;
    if ((r + 1) * r / 2 <= n) {
        cout << min(r + y, r + 1 + n - (r + 1) * r / 2) << "\n";
    } else {
        cout << r + y << "\n";
    }
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}