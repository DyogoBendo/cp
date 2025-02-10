#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long

vector<ll> v;

int n;
ll s;
ll ma;

void solve(){
    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if(n == 1 || n == 2){
        cout << "-1" << endl;
        return;
    }

    s= 0;

    for (int i = 0; i < n; i++)
    {
        s += v[i];
    }

    sort(v.begin(), v.end());

    ll x = (2 * n * v[n/2]) - s;

    if(x < 0) cout << 0 << endl;
    else cout << x + 1 << endl;
}
signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}