#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ans += 4 * m;
        if(i >  0){
            ans -= 2 *(m - x +  m - y);
        }
    }

    cout << ans << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
}