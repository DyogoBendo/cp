#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long


void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> psum(n + 1, 0);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        psum[i + 1] = psum[i];
        if(v[i] > i) continue;        
        if(v[i] > 0) ans += psum[v[i] - 1];
        psum[i + 1]++;
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}