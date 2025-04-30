#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

ll lcm(int x, int y){
    return (ll) x/gcd(x, y) * y;
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> prefix(n+1);
    vector<int> suffix(n+1);

    for (int i = 0; i < n; i++)
    {
        prefix[i+1] =  gcd(prefix[i], v[i]);
        suffix[n-i-1] = gcd(suffix[n-i], v[n-i-1]);
    }    
    
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = lcm(ans, gcd(prefix[i], suffix[i + 1]));
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}