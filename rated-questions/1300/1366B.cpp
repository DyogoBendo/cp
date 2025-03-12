#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n, x, m;
    cin >> n >> x >> m;

    int l = x, r = x;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(a < l && b >= l){
            l = a;
            r = max(b, r);
        } else if(b > r && a <= r){
            l = min(a, l);
            r = b;
        }
    }
    
    cout << (r - l + 1) << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}