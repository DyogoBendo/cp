#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);    

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }    

    sort(p.begin(), p.end());
    
    ord_set<int> s;

    ll ans = 0;
    for (auto [_, x] : p)
    {
        int sz = s.size();
        int sm = s.order_of_key(x);
        ans += (ll) sz - sm;
        s.insert(x);
    }

    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}