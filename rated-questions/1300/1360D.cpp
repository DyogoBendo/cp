#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if(n % i == 0){
            if(i <= k) ans = max(i, ans);
            if(n/i <= k) ans = max(ans, n/i);
        } 
    }
    
    cout << n/ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}