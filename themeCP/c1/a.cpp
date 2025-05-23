#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << v[n-1] - v[0] + v[n-2]-v[0] + v[n-2]-v[1] + v[n-1] - v[1] << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}