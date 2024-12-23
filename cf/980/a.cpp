#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;

    int x = b - a;

    if(x <= 0){
        cout << a << endl;
    } else{
        int ans = max(0, a - x);
        cout << ans << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}