#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n, k, l;
    cin >> n >> k >> l;

    cout << n*k/l + (n*k%l > 0) << endl;
}

signed main(){
    flash;
    solve();
}