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

    ord_set<pair<ll, ll>> s_even, s_odd, s;
    s_odd.insert({0, 0});
    s_even.insert({0, 0});


    ll psum = 0, psum_even = 0, psum_odd = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        psum = -psum;
        psum += v[i];
        int less;
        if(i & 1){
            psum_odd += v[i];
            less = s_even.order_of_key({psum, -1});
            s.insert({psum, i});
        } else{
            psum_even += v[i];
            less =  s_odd.order_of_key({psum, -1});
            s.insert({psum, i});
        }
        dbg(i, psum, less);
        ans += less;
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}