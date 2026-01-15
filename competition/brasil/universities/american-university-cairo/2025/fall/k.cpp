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


    vector<int> position(n);

    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) position[v[i]] = i;

    int l = position[0];
    int r = position[0];
    ll curr_mex = 1;

    ord_set<int> s;

    ll ans = 0;
    for(int i = 1; i < n; i++){
        // quantas posições para incluir o número i (ele pode ja estar incluso)
        int x = position[i];

        dbg(l, r, x);

        if(x >= l and x <= r){
            curr_mex++;
            continue;
        }

        ll a, b;
        if(x < l) a = l - x, b = n - r;
        else a = l+1, b = x - r;

        if(x < l) l = x;
        else r = x;

        dbg(curr_mex, a, b);
        ans += curr_mex * a * b;
        curr_mex++;
    }
    dbg(curr_mex);
    ans += curr_mex;
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}