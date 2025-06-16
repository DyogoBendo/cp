#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int check(int x, int y, int z){
    int total = 0;

    if(x > y) total += x - y;
    else total += min(y % x, x - (y % x));
    if(x > z) total += x - z;
    else total += min(z %x, x - (z % x));

    return total;
}

void solve(){
    int x, y, z;
    cin >> x >> y >> z;

    int ans = 1e4;
    for (int i = 1; i < max({x, y, z}); i++)
    {        
        ans = min(ans, abs(i - x) + check(i, y, z));        
        ans = min(ans, abs(i - y) + 1 + check(i, x, z));        
        ans = min(ans, abs(i - z) + 1 + check(i, y, x));        
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}