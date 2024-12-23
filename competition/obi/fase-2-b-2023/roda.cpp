#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, p, b;
    cin >> n >> b >> p;


    int ans = (b + p) % n;

    if(ans == 0) ans = n; 
    cout << ans << endl;

}