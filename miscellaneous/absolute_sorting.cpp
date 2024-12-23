#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (auto &x: v)cin >> x;


    int mn = 0;
    int mx = 1e9;

    for (int i = 0; i < n - 1; i++)
    {
        if(v[i] < v[i + 1]){
            mx = min(mx, (v[i] + v[i + 1]) / 2);
        }
        if(v[i] > v[i + 1]){
            mn = max(mn, (v[i] + v[i + 1] + 1) / 2);
        }
    }        
    
    if(mx < mn) cout << -1 << endl;
    else cout << mn << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}