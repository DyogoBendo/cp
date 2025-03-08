#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n;
    cin >> n;

    cout << n;
    for (int i = 0; i < n - 1; i++)
    {
        cout << " " << i + 1;
    }
    cout << endl;
    
}

signed main(){
    flash;
    int t;
    t = 1;

    while(t--) solve();
}