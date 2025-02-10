#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    int lo = 0;
    int hi = n;

    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;

        if(mid + k - 1 < n){
            lo = mid + 1;
        } else{
            hi = mid;
        }
    }
    lo--;

    int b = (n - lo) - 1;

    if(lo % 2 == 0){
        if(b % 4 == 0 || b % 4 == 1){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    } else{
         if(b % 4 == 1 || b % 4 == 2){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }


}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}