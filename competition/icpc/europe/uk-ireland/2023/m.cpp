#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int a, b, c;
    cin >> a >> b >> c;

    int ans= 2*a;

    if(c >= 2){
        ans += (2*b);
        ans += 3;
        c -= 2;
    }
    ans += 3 * (c/2);

    cout << ans << endl;
}