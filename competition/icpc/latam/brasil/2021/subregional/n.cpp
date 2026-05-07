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

    int y, n;
    cin >> y >> n;

    vector<int> v(y);
    for(int i = 0; i < y; i++) cin >> v[i];

    vector<int> classified(n);
    vector<tuple<int, int, int, int>> q;
    for(int i = 0; i < n; i++){
        int a, p, f;
        cin >> a >> p >> f;
        a--;

        if(v[a] >= p) classified[i] = 1;

        q.push_back({a, p, -1, i});
        q.push_back({a+f, p, 1, i});
    }

    vector<int> ans(n);
    sort(q.begin(), q.end());

    ord_set<pair<int, int>> s;
 
    int lst_y = 0;
    for(auto [x, p, o, i] : q){
        while(lst_y <= x){
            s.insert({-v[lst_y], lst_y});
            lst_y++;
        }
        int cnt_less = s.order_of_key({-p, 1e9});
        ans[i] += cnt_less*o;
    }   
    
    for(int i = 0; i < n; i++) if(classified[i]) ans[i] = 0;
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
}