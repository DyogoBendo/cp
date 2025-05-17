#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a > c or (a == c && b >= d)){
        cout << "Yes" << endl;
    } else cout << "No" << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}