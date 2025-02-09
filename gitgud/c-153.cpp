// https://codeforces.com/contest/1860/problem/C

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    bool win = false;
    int winner;
    int smaller = n + 1;
    int ans = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(i != 0){
            if(!win && x > smaller){
                ans ++;
                win = true;
                winner = x;
            } else if(win && !(x > winner || x < smaller)){
                ans ++;
                winner = min(x, winner);
            } 
        }
        smaller = min(smaller, x);

    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}