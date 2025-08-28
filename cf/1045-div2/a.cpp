#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, a, b;
    cin >> n >> a >> b;

    if(b >= n){
        cout << "YES" << endl;
        return;
    }
    if(b >= a){
        if(b % 2 != n%2){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    } else{
        if(b % 2 != a%2 or b%2 != n%2){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}