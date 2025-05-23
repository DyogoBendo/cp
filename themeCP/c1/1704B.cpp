#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans=0;
    int mn = v[0], mx = v[0];

    for (int i = 1; i < n; i++)
    {
        if(v[i] < mn){
            mn = v[i];
        }
        if(v[i] > mx) mx = v[i];

        int m = (mx + mn) / 2;
        if(m - mn > x or mx - m > x){
            mn = v[i];
            mx= v[i];
            ans++;
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