#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> cnt(31, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        for (int j = 0; j < 31; j++)
        {
            cnt[j] += (x >> j) & 1;
        }        
    }

    int ans = 0;
    for (int i = 30; i >=0; i--)
    {
        if(cnt[i] >= n - k){            
            ans += 1 << i;
            k -= n - cnt[i];
        }
    }
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}