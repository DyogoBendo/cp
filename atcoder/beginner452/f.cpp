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
    ll n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ord_set<int> s;

    ll curr = 0;
    int r = 0, lr = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        dbg(curr, r, lr);
        if(i){
            int cnt= s.order_of_key(v[i-1]);
            dbg(cnt);
            curr -= cnt;
            s.erase(v[i-1]);
        }
        while(r < n and curr + sz(s) - s.order_of_key(v[r]) < k){
            dbg(r, v[r], s.order_of_key(v[r]));
            curr += sz(s) -  s.order_of_key(v[r]);
            s.insert(v[r]);
            r++;
        }        


        bool first = true;

        while(r < n and curr + sz(s) -  s.order_of_key(v[r]) <= k){
            dbg(r, v[r], s.order_of_key(v[r]));
            curr += sz(s) - s.order_of_key(v[r]);
            s.insert(v[r]);
            if(first) lr = r, first = false;
            r++;
        }    
        lr = max(lr, i);
            

        dbg(r, lr);
        if(curr == k) ans += (r - lr);
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}