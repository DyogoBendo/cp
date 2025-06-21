#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    bool possible = false;
    if(l1 == l3){
        if(b1 + b2 + b3 == l1)  possible = true;        
    } else if(b1 == b3){
        if(l1 + l2 + l3 == b1) possible = true;
    }

    if(l3 + l2 == l1 && b3 == b2 && b2 + b1 == l1) possible=  true;
    if(b3 + b2 == b1 && l3 == l2 && l2 + l1 == b1) possible=  true;

    cout << (possible ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}