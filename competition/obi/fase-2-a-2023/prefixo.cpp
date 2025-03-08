#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n, m, ans =0;
    string s, r;
    cin >> n >> s >> m >> r;

    for (int i = 0; i < min(n, m) && s[i] == r[i]; i++, ans++);
    
    cout << ans << endl;
}

signed main(){
    flash;
    int t = 1;
    // cin >> t;

    while(t--) solve();
}