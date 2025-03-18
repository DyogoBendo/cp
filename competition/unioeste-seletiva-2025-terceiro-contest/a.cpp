#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;    

    if(!(1&n) && n>2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}