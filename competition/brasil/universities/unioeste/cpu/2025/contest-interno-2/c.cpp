#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;

    int x = max(a, b);
    int y = min(a, b);

    int ans = 0;

    int diff = min(y, x - y);
    ans = diff;
    y -= diff;
    ans += (y / 3) * 2;     
    if(y % 3 == 2) ans ++;    

    cout << ans << endl;
}

signed main(){
    flash;
    int t;
    cin >> t;

    while(t--) solve();
}