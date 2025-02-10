#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    ll l, r;

    cin >> l >> r;

    int c = 0;

    int s = 1;
    while(l <= r){
        c ++;
        l += s;
        s++;
    }

    cout << c << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}