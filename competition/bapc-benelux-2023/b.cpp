#include <bits/stdc++.h>
using namespace std;

#define ll long long


signed main(){
    ll n;
    cin >> n;

    int ans = 0;
    int r = 0;

    while(n > 1){
        ans++;
        if(n % 2) r = 1;
        n>>=1;
    }
    cout << (ans + (r + n)) <<endl;
}