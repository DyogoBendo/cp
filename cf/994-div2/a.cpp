#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int lst_zero = -1;   
    int ans = 0;
    int non_zero_sequence = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 0){
            non_zero_sequence = 0;
        } else{
            if(!non_zero_sequence) ans ++;
            non_zero_sequence = 1;
        }
    }    
    ans = min(ans, 2);

    cout << ans << endl;    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}