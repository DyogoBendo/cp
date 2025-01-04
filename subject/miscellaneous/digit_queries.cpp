#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int k;
    cin >> k;

    int d = 0;
    int s = 0;

    int pot = 1;
    int group_size;

    while(k > s){
        d ++;
        group_size = d * 9 * pot;
        s += group_size;
        pot *= 10;
    }

    k -= (s - group_size) + 1;


    int number = (k / d) + (pot / 10);        
    int position = k % d;    
    
    while(d - 1 - position){
        number /= 10;
        position ++;
    }

    cout << number % 10 << endl;

}

signed main(){
    int q;
    cin >> q;

    while(q--) solve();
}