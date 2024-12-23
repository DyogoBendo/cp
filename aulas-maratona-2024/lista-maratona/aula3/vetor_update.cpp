#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, u, q;
    cin >> n >> u;

    vector<int> v(n + 1, 0);

    for (int i = 0; i < u; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        r++;
        v[l] += x;
        v[r] -= x;
    }

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        c += v[i];
        v[i] = c;
    }
    
    
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int j;
        cin >> j;
        cout << v[j] << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}