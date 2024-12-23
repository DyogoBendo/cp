#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    if(k == 1 || k == n){
        if(n == 1) cout <<1 << endl << 1 << endl;
        else cout << -1 << endl;
    } else{
        int a = k - 1;
        int b = k + 1;

        if(a % 2 == 0){
            a --;
            b ++;
        }

        cout << 3 << endl;
        cout << 1 << " " << a + 1 << " " << b << endl;
        
    }
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}