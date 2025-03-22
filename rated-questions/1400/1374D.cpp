#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    map<int, int> m;

    int bvalue = 1;
    int bx = -1;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x%k == 0) continue;
        m[x%k]++;        
        if(m[x%k] > bvalue){
            bvalue = m[x%k];
            bx = k - x%k;
        } else if(m[x%k] == bvalue){
            bx = max(bx, k - x%k);
        }
    }
            
    ll ans = (ll) (bvalue - 1) * k + bx + 1;
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}