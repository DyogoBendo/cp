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

    sort(v.begin(), v.end());

    int c = v[0];
    for (int i = 1; i < n; i++)
    {
        c = (c + v[i]) / 2;
    }

    cout << c << endl;    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}