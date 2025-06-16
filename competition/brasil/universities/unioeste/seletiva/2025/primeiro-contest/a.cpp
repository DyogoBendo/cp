#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n;
    cin >> n;    
    vector<int> v(n);

    for (auto &x : v) cin >> x;

    sort(v.begin(), v.end());

    int ans = v[n - 1] - v[0] + 1;
    for (int i = 0; i < n - 1; i++)
    {                
        ans = min(v[i] + 360 - v[i + 1] + 1, ans);                
    }
    
    cout << ans << endl;
}

signed main(){
    flash;
    int t;
    t = 1;

    while(t--) solve();
}