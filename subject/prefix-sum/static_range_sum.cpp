#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> psum(n + 1);

    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + v[i - 1];
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        cout << psum[r] - psum[l] << endl;
    }
    
}