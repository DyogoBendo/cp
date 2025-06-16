#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n;
    cin >> n;
    int total = 0;
    int x = 1e4 + 10;

    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        total += curr;
        x = min(x, curr);
    }
    
    cout << (total - x *n) << endl;
}

signed main(){
    flash;
    int t = 1;
    // cin >> t;

    while(t--) solve();
}