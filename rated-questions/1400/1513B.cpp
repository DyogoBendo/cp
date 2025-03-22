#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MOD = 1e9+7;

int fat(int x){
    int curr = 1;
    for (int i = 1; i <= x; i++)
    {
        curr = (ll) curr * i % MOD;
    }
    return curr;
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
    }

    int curr = v[0];
    for (int i = 0; i < n; i++)
    {
        curr &= v[i];
    }    
    if(m[curr] < 2){
        cout << 0 << endl;
        return;
    }

    int pick_borders = (ll) m[curr] * (m[curr] - 1) % MOD;    
    int ans = (ll) fat(n-2) * pick_borders % MOD;

    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}