#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> entries(n);
    vector<int> xs;
    vector<int> ys;

    for (int i = 0; i < n; i++)
    {
        cin >> entries[i].first >> entries[i].second;
        xs.push_back(entries[i].first);
        ys.push_back(entries[i].second);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    vector<int> xsum(n+1, 0);
    vector<int> ysum(n+1, 0);

    for (int i = 0; i < n; i++)
    {
        xsum[i+1] = xsum[i] + xs[i];
        ysum[i+1] = ysum[i] + ys[i];
    }
    
    int dst_min = 1e15, ans = 0;
    set<pair<int, int>> pset;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(pset.count({xs[i], ys[j]})) continue;
            pset.insert({xs[i], ys[j]});
            int dst = xs[i] * (2*i - n) + xsum[n] - 2*xsum[i];
            dst += ys[j] * (2*j - n) + ysum[n] - 2*ysum[j];

            if(dst < dst_min){
                dst_min = dst;
                ans = 1;
            } else if(dst == dst_min) ans ++;
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