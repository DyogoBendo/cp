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

int cnt_inv(vector<int> &v){
    ord_set<int> os;
    int tot = 0;
    for(int i = sz(v) - 1; i >=0; i--){
        tot ^= os.order_of_key(v[i]) & 1;
        os.insert(v[i]);
    }
    return tot;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    set<int> s;

    bool possible = true;
    for(int i = 0; i < n; i++) s.insert(a[i]);
    for(int i = 0; i < n; i++) if(!s.count(b[i])) possible = false;
    
    int inv1 = cnt_inv(a), inv2 = cnt_inv(b);

    if(inv1 != inv2) possible = false;
    cout << (possible ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}