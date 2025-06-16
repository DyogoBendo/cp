#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    ll n;
    cin >> n;
    vector<ll> players(n);

    for (ll &x : players) cin >> x;

    sort(players.begin(), players.end());

    ll cur, ans = INT64_MAX;
    for (ll i = 0, j = n-1; i < j; i++, j--)
    {
        cur = players[i] + players[j];
        ans = min(ans,cur);
    }""
    
    cout << ans << endl;
    
}