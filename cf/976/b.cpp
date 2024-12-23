#include <bits/stdc++.h>

using namespace std;

#define int long long

int k;
bool check(int n){
    int s = sqrtl(n);
    int v = n - s;    
    return v < k;
}

void solve(){
    cin >> k;


    int lo = 0, hi = 9e18;

    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;

        if(check(mid)){
            lo = mid + 1;
        } else{
            hi = mid;
        }
    }

    cout << lo << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}