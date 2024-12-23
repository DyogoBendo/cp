#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int x0, y0;
    cin >> x0 >> y0;

    int initial_color = (x0 + y0) %2;
    int possible = 1;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        if((x + y) % 2 == initial_color) possible = 0;
    }
    
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}