#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    int ans = 0;    

    int md = (m - 1) * k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int diff = abs(x - h);

        if(diff){
            if(diff <= md && diff % k == 0){                
                ans ++;
            }
        }        
    }    

    cout << ans << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}