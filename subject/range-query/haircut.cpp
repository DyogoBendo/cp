#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

#define int long long

signed main(){
    setIO("haircut");

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ord_set<pair<int, int>> s;
    vector<int> count(n+1, 0);
    int tot = 0;

    for(int i = 0; i < n; i++){
        int x = v[i];
        int add = (i) - s.order_of_key({x, i});   
        count[x] += add;
        tot += add;

        s.insert({x, i});
    }

    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
        tot -= count[i];
        ans[i] = tot;
    }
    for(auto a : ans) cout << a << endl;

}