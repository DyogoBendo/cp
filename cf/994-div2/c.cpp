#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    x--;
    y--;
    int k1 = min(x, y);
    int k2 = max(x, y);        
    int change = (k1 %2 == k2 % 2) ;
    if(n % 2 == 0){
        for (int i = 0; i < n; i++)
        {
            if(i == k1 && change) cout << 2;
            else cout << i % 2;
            cout << " ";
        }
        cout << endl;        
    } else{
        int position2 = 0;
        if(k2 == n - 1) position2 = n - 1;
        int has_end = k1 == 0 || k2 == n - 1;
        
        int even = k1 % 2;
        for (int i = 0; i < n; i++)
        {
            if(i == position2) cout << 2;
            else{
                if(change && !has_end && (k2 == i)){
                    cout << 2;                    
                } else{
                    cout << i % 2;
                }
            }
            cout << " ";
        }
        cout << endl;
    }

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}