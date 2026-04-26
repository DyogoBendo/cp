#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll psum = 0;

    ord_set<pair<ll, int>> s;

    vector<int> inv(n);

    s.insert({0, -1});
    for(int i = 0; i < n; i++){        
        int x = s.order_of_key(make_pair(psum, -2));
        inv[i] = x;        

        psum += v[i];
        s.insert({psum, i});
    }

    ord_set<int> s2;
    for(int i = 1; i<= n; i++) s2.insert(i);

    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){                
        auto x = s2.find_by_order(sz(s2) - inv[i] - 1);
        ans[i] = *x;
        s2.erase(x);
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}