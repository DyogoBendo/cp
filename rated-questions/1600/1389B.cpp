#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k, z;
    cin >> n >> k >> z;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int curr = 0;
    int bst_duo = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        curr += v[i];
        if(i < n-1)bst_duo = max(bst_duo, v[i] + v[i+1]);        
        if(i > 0)bst_duo = max(bst_duo, v[i] + v[i-1]);

        if(i%2 != k%2) continue;
        int lf = (k - i) / 2;
        if(lf > z) continue;
        ans = max(ans, curr + bst_duo*lf);
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}