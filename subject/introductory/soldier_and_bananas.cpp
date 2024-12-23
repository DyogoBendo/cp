#include <bits/stdc++.h>

using namespace std;

int main(){
    long long k, n, w;
    cin >> k >> n >> w;

    long long ans = max(k * ((w * (w + 1)) / 2) - n, 0LL);

    cout << ans << endl;

}