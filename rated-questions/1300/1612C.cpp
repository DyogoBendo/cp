#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long

int calc(int n, int k){
    if(n <= k){
        return (n + 1) * (n) / 2;
    }
    int mid = (k + 1) * (k) / 2;
    int after = n - k;

    return mid + ((2*k - after - 1) * (after) / 2);
}

void solve(){
    int k, x;
    cin >> k >> x;

    int l = 0, r = 2*k - 1;

    while(l < r){
        int m = (r - l) / 2 + l;                
        if(calc(m, k) < x){
            l = m + 1;
        } else{
            r = m;
        }
    }

    cout << r << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}