#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    long long n, m;
    cin >> n >> m;
 
    if(n % m == 0){
        cout << 0 << endl;
        return;
    } 

    int test_m = m;

    while(!(test_m % 2)){
        test_m /= 2;
    }
    long long current = n % m;

    if(current % test_m != 0){
        cout << -1 << endl;
        return;
    }
    long long total = 0;
    while(current){        
        total += current;
        current = (current * 2) % m;
    }
    cout << total << endl;
}
 
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}