#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int x;
    cin >> x;
    cout << __builtin_popcount(x) << endl;
}

signed main(){
    flash;
    solve();
}