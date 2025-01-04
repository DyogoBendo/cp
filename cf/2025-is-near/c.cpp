#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    int curr = 0;
    int seg = n;
    int ans = 0;
    int p = 1;            
    int m;    
    int prev = 0;
    while(seg >= k){                        
        m = (seg + 1) / 2;                 
        if(seg % 2) ans += (m * p) + prev;
        curr += m;                
        seg /= 2;
        prev = curr * p;
        p*=2;
    }
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}