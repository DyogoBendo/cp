#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> ans(n);
    
    ans[0] = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        ans[i] = i;
    }

    int k = 1;
    for (int i = n / 2 + 1 ; i < n; i++)
    {
        ans[i] = k;
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
}