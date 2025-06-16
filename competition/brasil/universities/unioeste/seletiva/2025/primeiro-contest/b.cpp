#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n;
    cin >> n;

    cout << ((n << 1) ^ n) << endl;
}

signed main(){
    flash;
    int t;
    t = 1;

    while(t--) solve();
}