#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int a1, a2, a3;

    a3 = min(26, n - 2);
    n -= a3;
    a2 = min(26, n - 1);
    n -= a2;    

    char b1, b2, b3;
    b1 = 'a' + n - 1;
    b2 = 'a' + a2 - 1;
    b3 = 'a' + a3 - 1;

    cout << b1 << b2 << b3 << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--)solve();
}