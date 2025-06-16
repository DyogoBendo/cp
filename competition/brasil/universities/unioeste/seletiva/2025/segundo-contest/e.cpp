#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n, u;
    cin >> n >> u;

    vector<int> v(n + 1, 0);

    for (int i = 0; i < u; i++)
    {
       int l, r, val;
       cin >> l >> r >> val;
       v[l] += val;
       v[r + 1] -= val; 
    }

    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += v[i];
        v[i] = curr;
    }
    int q;
    cin >> q;
    while(q--){
        int idx;
        cin >> idx;

        cout << v[idx] << endl;
    }
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}