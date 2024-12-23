#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int positive = 0;
    int negative = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 1) positive ++;
        else negative ++;
    }
    int operations = 0;
    if(negative > positive){
        operations = (negative - positive + 1) / 2;
        negative = negative - operations;
    }

    if(negative % 2 == 1) operations ++;
    cout << operations << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}