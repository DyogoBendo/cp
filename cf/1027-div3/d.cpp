#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MAX = 1e9+10;
const int MIN = -1;

ll calc(ll l, ll r, ll b, ll t){
    return (t - b + 1) * (r - l + 1);
}

void solve(){
    int n;
    cin >> n;

    set<pair<int, int>> ls, rs, ts, bs;    

    vector<pair<int, int>> v(n);

    int mnx = MAX, maX = MIN;
    int mny = MAX, maY = MIN;


    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        v[i].first = x;
        v[i].second = y;

        mnx = min(mnx, x);
        mny = min(mny, y);
        maX = max(maX, x);
        maY = max(maY, y);

        ls.insert({x, i});
        rs.insert({-x, i});
        ts.insert({-y, i});
        bs.insert({y, i});
    }

    ll ans = 1e18;

    for (int i = 0; i < n; i++)
    {
        int x = v[i].first;
        int y = v[i].second;

        if(x != mnx && x != maX && y != mny && y != maY) continue;

        ls.erase({x, i});
        rs.erase({-x, i});
        ts.erase({-y, i});
        bs.erase({y, i});

        int l = ls.begin()->first;
        int r = -rs.begin()->first;
        int t = -ts.begin()->first;
        int b = bs.begin()->first;

        if(calc(l, r, b, t) < n){
            ans = min({calc(l, r, b, t+1), ans, calc(l, r+1, b, t)});
        } else{
            ans = min(ans, calc(l, r, b, t));
        }


        ls.insert({x, i});
        rs.insert({-x, i});
        ts.insert({-y, i});
        bs.insert({y, i});
    }
    
    cout << ans << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}