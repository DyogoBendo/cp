#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;

    int s = a + 2 * b;

    int m = (s / 2);

    int dois = m / 2;
    int um = 0;
    
    if(dois > b){
        um = m - 2 * b;
    } else{
        um = m % 2;
    }

    if(s %2 == 0 && um <= a){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}