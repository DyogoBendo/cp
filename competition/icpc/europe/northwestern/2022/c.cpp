#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double
const ld EPS = 1e-9;


signed main(){
    darvem;
    ll tot;
    cin >> tot;

    ld l = 0, r = 1e5;

    auto check = [&](ld r){
        ll cnt = 0;

        for(int i=1; i <= r; i++){
            cnt += sqrtl(r*r - i*i);
        }

        cnt *= 4;

        return cnt > tot;
    };

    ld ans;
    cout << setprecision(13) << fixed;
    while(r-l > EPS){
        ld m = (r + l) / 2;         
        if(check(m)){
            ans = m;
            r = m;
        } else l = m;
    }

    cout << ans << endl;

}