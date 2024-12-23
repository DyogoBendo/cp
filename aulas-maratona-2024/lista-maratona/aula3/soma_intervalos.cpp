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

    vector<int> ps(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        ps[i] += ps[i - 1] + v[i - 1];
    }
    
    
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << ps[b] - ps[a - 1] << endl;
    }

}