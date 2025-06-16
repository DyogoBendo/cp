#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    double n, k, l, r;
    cin >> n >> k >> l >> r;

    double doces;
    bool isTrue = true;
    doces = k/n;
    if(doces < l) isTrue = false;
    if(doces > r) isTrue = false;

    if(isTrue) cout << 'S' << endl;
    else cout << 'N' << endl;
}