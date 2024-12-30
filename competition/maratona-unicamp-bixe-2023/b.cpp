#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll m, n;
    cin >> m >> n;

    ll a,b,c;
    a = (m*m) - (n*n);
    b = 2*m*n;
    c = (m*m) + (n*n);

    cout << a << " " <<  b << " " << c << endl;
}