#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll TAMANHO = 3e6;
#define int long long

signed main () {
    ll n;
    cin >> n;

    vector<tuple<ll,ll,ll>> waves;
    vector<ll> m(TAMANHO+1);

    for (ll i = 0; i < n; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        waves.push_back({a,b,c});
    }

    sort(waves.begin(), waves.end());

    ll best = 0, cur = 0;
    int lst = 0;
    for (auto wave: waves)
    {
        int time = get<0>(wave);
        int fun = get<1>(wave);
        int wait = get<2>(wave);

        int end = time + wait;

        while(lst <= time){
            cur = max(cur, m[lst]);
            lst ++;
        }
        m[end] = max(m[end], cur + fun);
    }

    for (auto x: m)
    {
        best = max(best, x);
    }
    
    cout << best << endl;
}