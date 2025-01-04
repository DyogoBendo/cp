#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int psum = 0;

    map<int, int> m;
    m[0] = 1;
    int ans =0;

    for (int i = 0; i < n; i++)
    {
        psum += v[i];        
        ans += m[psum - x];

        m[psum]++;

    }

    cout << ans << endl;
}