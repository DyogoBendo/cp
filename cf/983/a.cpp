#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int on = 0, of = 0;
    for (int i = 0; i < 2*n; i++)
    {
        int x;
        cin >> x;
        if(x) on ++;
        else of++;
    }
    
    // maximo de desligado é se todos estarem em pares, no caso sera um se for impar

    cout << on % 2 << " ";

    // maximo de ligado sera se eu pegar todos os pares separados e subrair


    if(on <= n) cout << on;
    else cout << n - (on -n);
    cout << endl;

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}