#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    sort(cnt.begin(), cnt.end(), greater<int>());

    int ans = 0;    
    for (int i = 0; i < n; i++)
    {
        if(i > 0 && cnt[i - 1] <= cnt[i]) cnt[i] = cnt[i-1] - 1;
        if(cnt[i] <= 0) break;        
        ans += cnt[i];
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}