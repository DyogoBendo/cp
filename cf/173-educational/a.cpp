#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    int ans = 1;

    while(n > 3){
        n /= 4;
        ans *= 2;
    }
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}