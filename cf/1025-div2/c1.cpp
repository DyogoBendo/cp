#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, x;
    cin >> n;
    
    cout << "digit" << endl;
    cout.flush();
    cin >> x;
    cout << "digit" << endl;
    cout.flush();
    cin >> x;

    cout << "add -8" << endl;
    cout.flush();
    cin >> x;
    
    cout << "add -4" << endl;
    cout.flush();
    cin >> x;
    
    cout << "add -2" << endl;
    cout.flush();
    cin >> x;
    
    cout << "add -1" << endl;
    cout.flush();
    cin >> x;

    cout << "add " << n-1 << endl;
    cout.flush();
    cin >> x;

    cout << "!" << endl;
    cout.flush();
    cin >> x;    
}


signed main(){    
    int t = 1;
    cin >> t;

    while(t--) solve();
}