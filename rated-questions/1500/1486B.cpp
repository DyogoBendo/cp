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

    int xposs = n % 2 ? 1 : xs[n/2] - xs[n/2-1] + 1;
    int yposs = n % 2 ? 1 : ys[n/2] - ys[n/2-1] + 1;
    
    cout << xposs * yposs << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}