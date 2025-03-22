#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dst(n, 0);
    dst[0] = 1;

    for (int i = 1; i < n; i++)
    {        
        dst[i] = 2*v[i] > v[i-1];        
    }    
        
    int cnt = 0, ans = 0;
    for (int i = 1; i <= k; i++)
    {
        cnt += dst[i];
    }
    ans = cnt == k;
    int l = 1, r = k;
    while(r < n - 1){
        cnt -= dst[l];
        cnt += dst[r+1];        

        ans += cnt == k;
        l ++, r ++;
    }
    
    cout << ans << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}