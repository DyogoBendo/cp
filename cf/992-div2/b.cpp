#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return;
    } 

    int ans = 2; // preciso colocar nas duas pontas

    int curr = 1;
    int total = curr + 1;
    while(total < (n / 2) + (n % 2)){
        curr = (curr + 1) * 2;
        total = curr + 1;
        ans ++;
    }

    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}