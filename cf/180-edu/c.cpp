#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];        
    }

    ll ans = 0;        
    for (int i = 0; i < n; i++)
    {                
        for (int j = 0; j < i; j++)
        {
            int curr = v[i] + v[j];

            int needed = max(v[i] - v[j], v[n-1] - curr);

            ans += j - (upper_bound(v.begin(), v.begin() + j, needed) - v.begin());
        }        
    }
    
    cout << ans << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}