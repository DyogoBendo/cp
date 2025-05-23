#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    if(n >= 3) cout << 3 << " ";
    cout << 1 << " ";
    for (int i = 4; i <= n; i++)
    {
        cout << i << " ";
    }
    if(n >= 2) cout << 2;
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}