#include <bits/stdc++.h>

using namespace std;

void solve(){    
    long long a, b, c;
    cin >> a >> b >> c;
    
    long long total = a + b + c;

    long long check = 2;

    int possible = 0;

    while(check < 6){
        check ++;
        if(total % check) continue;
        long long part = total / check;
        if(a % part == 0 && b % part == 0 && c % part == 0){            
            possible = 1;
        }
    }

    if(possible){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }



}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}