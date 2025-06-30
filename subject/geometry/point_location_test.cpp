#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    vector<pair<int, int>> v(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    pair<int, int> v1 = {v[1].first - v[0].first, v[1].second - v[0].second};
    pair<int, int> v2 = {v[2].first - v[1].first, v[2].second - v[1].second};

    int cross = v1.first*v2.second - v1.second * v2.first;

    cout << (cross == 0 ? "TOUCH" : cross > 0 ? "LEFT" : "RIGHT") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}