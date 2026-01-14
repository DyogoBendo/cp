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

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> cities(m);

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        cities[--a]++;
    }

    vector<pair<ll, int>> occ;
    for(int i = 0; i < m; i++) occ.push_back({cities[i], i});

    sort(occ.begin(), occ.end());

    vector<ll> p;
    ll curr = 0;        
    p.push_back(0);
    for(int i = 1; i < m; i++){
        curr += (occ[i].first - occ[i-1].first) * i;
        p.push_back(curr);
    }

    vector<pair<ll, int>> queries;
    for(int i = 0; i < q; i++){
        ll k;
        cin >> k;
        queries.push_back({k-n, i});
    }

    sort(queries.begin(), queries.end());

    vector<int> ans(q);


    ord_set<int> s;
    int idx = 0;
    for(int i = 0; i < q; i++){        
        ll pos = lower_bound(p.begin(), p.end(), queries[i].first) - p.begin();
        
        while(sz(s) < pos) s.insert(occ[idx++].second);
        
        ll k = (queries[i].first - p[pos-1] - 1 + pos) % pos;        
        
        ans[queries[i].second] = *s.find_by_order(k)+1;                
    }

    for(auto a : ans) cout << a << endl;
}