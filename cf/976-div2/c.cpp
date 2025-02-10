#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int b, c, d;
    cin >> b >> c >> d;

    int possible = 1;
    int ans = 0;
    int p = 1;
    int i = 62;
    while(i-- && possible){
        int di = d % 2;
        d /=2;
        int bi = b % 2;
        b /= 2;

        int ci = c % 2;
        c /= 2;

        if((di && bi) || (!di && !bi)){
            ans += 0;
        } else if( (di && !ci) || (!di && ci)){
            ans += p;
        } else{
            possible = 0;
        }

        p *= 2;
    }

    if(!possible) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}