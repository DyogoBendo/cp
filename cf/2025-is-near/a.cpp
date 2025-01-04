#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    

    bool possible = false;
    for (int i = 1; i < n; i++)
    {
        int b = min(a[i - 1], a[i]);
        int c = max(a[i - 1], a[i]);
        if(2 * b > c) possible = true;        
    }
    
    if(possible) cout << "YES";
    else cout << "NO";
    cout << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}