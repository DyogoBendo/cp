#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    int mn = 1e9, mx = -1;
    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++)
    {        
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {        
        cin >> v2[i];
    }
    for (int i = 0; i < n; i++)
    {                
        mn = min(v1[i]-v2[i], mn);
        mx = max(v1[i]+v2[i], mx);
    }
    
    double ans = (mx + mn) / 2.0;

    printf("%.1lf\n", ans);
}


signed main(){
    //darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}