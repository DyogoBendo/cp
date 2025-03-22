#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dst;
    for (int i = 0; i < n-1; i++)
    {
        dst.push_back(v[i+1] - v[i] - 1);
    }    
    
    sort(dst.begin(), dst.end());

    int ans = n;
    for (int i = 0; i < n-k; i++)
    {
        ans += dst[i];
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}