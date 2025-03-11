#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    int ans = 0;

    if(n % 2 == 0){
        int k = n / 2 + 1;
        ans = k * k;
    } else{
        int a = n/2 + 1;
        int b = n/2 + 2;
        ans = 2* (a * b);
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}