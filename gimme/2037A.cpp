#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x] ++;
    }

    int ans = 0;

    for (int i = 0; i < n + 1; i++)
    {
        ans += v[i] / 2;
    }
    
    cout << ans << endl;
    
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}