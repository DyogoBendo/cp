#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak; 

    int d = min(m / k, ak);

    m -= d*k;
    
    int r = min(a1, m % k);
    
    m -= r;
    a1 -= r;
    int ka1 = a1 / k;
    
    int d2 = min(m/k, ka1);
    m -= d2*k;
    
    int ans = 0;
    ans += m / k;
    ans += m % k;

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}