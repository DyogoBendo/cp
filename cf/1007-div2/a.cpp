#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int k;
    cin >> k;

    k--;
    if(k % 3) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main(){
    flash;
    int t;
    cin >> t;

    while(t--) solve();
}