#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long

using namespace std;

void solve(){
    int k;
    cin >> k;

    int x = 0;
    while(k > 3){
        x ++;
        k >>= 2;        
    }        
    cout << (1 << x) << endl;
}

signed main(){
    flash;
    int t;
    cin >> t;

    while(t--) solve();
}