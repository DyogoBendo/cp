#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> prox(n, n);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(x > y) swap(x, y);
        prox[x] = min(y, prox[x]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        prox[i] = min(prox[i], prox[i+1]);
    }    
    
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {        
        ans += (prox[i] - i);
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}