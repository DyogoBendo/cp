#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int perfect = 1;

    vector<int>v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++)
    {
        int x = abs(v[i] - v[i - 1]);
        if(x != 5 && x != 7) perfect = 0;
    }

    if(perfect) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}