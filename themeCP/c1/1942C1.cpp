#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int>v(x);

    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < x - 1; i++)
    {
        if(v[i] + 2 == v[i+1]) ans++;
    }    
    if((v[x-1] == n-1 && v[0] == 1) or (v[x-1] ==n &&v[0] == 2)) ans++;
    
    cout << ans + x -2 << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}