#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;

    vector<int> found(n, 0);
    found[0] = 1;

    int psum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        psum += x;
        int k = abs((psum / n)) + 1;
        int m = ((k * n) + psum ) % n;           

        ans += found[m];

        found[m]++;
    }

    cout << ans << endl;
    
}