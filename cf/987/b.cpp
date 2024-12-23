#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    bool possible = true;
    for (int i = 0; i < n - 1; i++)
    {
        if(v[i] == i + 1) continue;
        if(v[i + 1] == i + 1 && v[i] == i + 2){
            swap(v[i + 1], v[i]);
            continue;
        }
        possible = false;        
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}