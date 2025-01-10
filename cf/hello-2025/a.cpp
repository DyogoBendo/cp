#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


void solve(){
    int n, m;
    cin >> n >> m;

    cout << 1 + max(n, m) << endl;
}

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}