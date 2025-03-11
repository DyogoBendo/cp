#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    int ans = 1;
    int k = n;
    for (int i = 2; i * i <= n; i++)
    {
        int p = 0;
        while(k % i == 0){
            p = i;
            k /= i;
        }   
        if(p) ans = max(ans, n/p);
    }
    
    cout << ans << " " << n - ans << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}