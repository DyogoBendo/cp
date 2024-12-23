#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int possible = 0;

    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < n; i++)
    {
        if(a[i] != c[i] && b[i] != c[i]) possible = 1;
    }
    

    if(possible) cout << "YES";
    else cout << "NO";

    cout << endl;
    
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}