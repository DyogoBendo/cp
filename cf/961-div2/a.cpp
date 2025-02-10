#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;


    if(k == 0){
        cout << k << endl;
        return;
    }

    if(k < n){
        cout << 1 << endl;
        return;
    }

    int ans = 1;
    int i = 1;
    k -= n;
    while(k > 0) {
        k -= n - i;
        ans ++;
        if(k <= 0) break;
        k -= n - i;
        ans ++;
        i ++;
    }
    
    cout << ans << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}