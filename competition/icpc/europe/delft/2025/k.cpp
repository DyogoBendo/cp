#include <bits/stdc++.h>
using namespace std;

signed main(){
    int c, n;
    cin >> c >> n;
    if (c > n) cout << 0;
    else if (c == n) cout << c;
    else cout << c+1;
    cout << '\n';
}