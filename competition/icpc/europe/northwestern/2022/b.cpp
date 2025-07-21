#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double

signed main(){
    darvem;

    ld h, r, da, dw;
    cin >> h >>r >> da >> dw;

    cout << setprecision(10) << fixed << (h * sqrt(da)) / (sqrt(dw)+sqrt(da)) << endl;
}