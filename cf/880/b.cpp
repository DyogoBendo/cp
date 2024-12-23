#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, k, g;
    cin >> n >> k >> g;
    long long total = 0;
    long long missing = k * g;    

    long long r = (g - 1) / 2;
 
    total = (n - 1) * r;
    if(total > k * g) total = k * g;
    missing = missing - total;
    long long a = missing % g;    
    if(a > r){
        total -= (g - a);
    } else{
        total += a;
    }

    cout << total << endl;

}


int main(){

    long long t;
    cin >> t;
    while(t--) solve();
}