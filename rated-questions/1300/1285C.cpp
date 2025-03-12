#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
    }

    int ma = 0;
    int curr = 0;
    for (int i = 0; i < n - 1; i++)
    {
        curr += v[i];
        if(curr <= 0) curr = 0;
        ma = max(ma, curr);
    }
    curr = 0;
    for (int i = 1; i < n; i++)
    {
        curr += v[i];
        if(curr <= 0) curr = 0;
        ma = max(ma, curr);
    }

    cout << (ma < total ? "YES" : "NO") << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}