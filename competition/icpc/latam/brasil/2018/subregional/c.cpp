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

signed main(){
    darvem;

    ll x, y, h, v;
    cin >> x >> y >> h >> v;

    dbg(x, y, h, v);

    vector<pair<int, int>> vh, vv;
    for(int i = 0; i < h; i++){
        int y1, y2;
        cin >> y1 >> y2;
        vh.push_back({y1, y2});
    }    
    for(int i = 0; i < v; i++){
        int y1, y2;
        cin >> y1 >> y2;
        vv.push_back({y1, y2});
    }

    sort(vh.begin(), vh.end());
    sort(vv.begin(), vv.end());

    ord_set<int> oh, ov;

    ll c1 = 0, c2 = 0;
    for(auto [a, b] : vh){
        int X =  oh.order_of_key(b);
        int k = sz(oh) - X;
        dbg(a, b, X, k);
        c1 += k;
        oh.insert(b);
    }
    for(auto [a, b] : vv){
        int X =  ov.order_of_key(b);
        int k = sz(ov) - X;
        c2 += k;
        ov.insert(b);
    }

    
    ll init = (h+1) * (v + 1);
    dbg(init, c1, c2);
    cout << init + c1 + c2 << endl;
}