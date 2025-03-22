#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> boy_pairs(a+1);
    vector<int> girl_pairs(b+1);

    vector<pair<int, int>> pairs(k);

    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        boy_pairs[x]++;
        pairs[i].first= x;
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        girl_pairs[x]++;
        pairs[i].second = x;
    }
    

    ll ans = 0;
    for (auto [x, y] : pairs)
    {        
        ans += (k - boy_pairs[x] - girl_pairs[y] + 1);
    }
    
    cout << ans / 2 << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}