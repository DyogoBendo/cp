#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int> psum(n+1, 0); 
    partial_sum(v.begin(), v.end(), psum.begin());
    
    int ans = 1e18;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, (a+b) * (v[i] - v[0]) + b*(psum[n] - psum[i] - (n - i) * v[i]));
    }
    
    cout << ans << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}