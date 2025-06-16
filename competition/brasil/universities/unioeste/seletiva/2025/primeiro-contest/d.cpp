#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(2*n);
    for(auto &x: v) cin >> x;

    sort(v.rbegin(), v.rend());

    int ans = 0;
    for (int i = 0; i < 2*n; i+= 2) ans += v[i];
    cout << ans << endl;
    
}

signed main(){
    flash;
    int t;
    t = 1;

    while(t--) solve();
}