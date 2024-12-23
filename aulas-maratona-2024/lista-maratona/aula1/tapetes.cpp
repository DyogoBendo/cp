#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, l;
    cin >> l >> n;
    
    long long ans = (l - n + 1) * (l - n + 1) + (n - 1);

    cout << ans << endl;   
}