#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int qtd = 0;
    int curr = -1;
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == curr){
            qtd ++;
        } else{
            qtd = 1;
            curr = x;
        }
        ans = max(ans, qtd);
    }

    cout << n - ans << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}