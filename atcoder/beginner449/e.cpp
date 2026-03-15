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

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> occ(m+1);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        dbg(i, v[i]);
        occ[v[i]]++;
    }

    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; i++){
        cin >> queries[i].first;        
        queries[i].second = i;
        queries[i].first --;
    } 

    sort(queries.begin(), queries.end());

    
    vector<pair<int, int>> nxt;
    vector<int> ans(q);
    for(int i = 1; i<= m; i++) nxt.push_back({occ[i], i});
    sort(nxt.begin(), nxt.end());
    
    int last_query = 0;
    ll tot = n;
    
    dbg(tot);
    while(last_query < q and queries[last_query].first < n){
        dbg(last_query, queries[last_query].first, queries[last_query].second);
        ans[queries[last_query].second] = v[queries[last_query].first];
        last_query++;
    }
    
    
    ord_set<int> curr_elements;
    curr_elements.insert(nxt[0].second);
    ll lst_cnt = nxt[0].first;
    ll pref = 1;
    for(int i = 1; i < sz(nxt); i++){
        auto [cnt_curr, xcurr] = nxt[i];        
        dbg(lst_cnt, cnt_curr, xcurr);

        if(lst_cnt != cnt_curr){        
            int diff = cnt_curr - lst_cnt;
            // preciso adicionar essa diff para todos do prefixo, então a quantidade de movimentos que eu tenho é exatamente pref*diff
            
            ll mov = pref*diff;
            dbg(diff, mov);
            
            while(last_query < q and queries[last_query].first < mov+tot){
                ll pos = ((queries[last_query].first) - tot) % pref;                
                dbg(last_query, queries[last_query].first, queries[last_query].second, pos);
                
                ans[queries[last_query].second] = *curr_elements.find_by_order(pos);
                last_query++;
            }
            lst_cnt = cnt_curr;
            tot += mov;
        } 
        curr_elements.insert(xcurr);
        pref ++;
    }

    while(last_query < q){
        ll pos = ((queries[last_query].first) - tot) % pref;                        
        ans[queries[last_query].second] = pos + 1;
        last_query++;
    }

    for(auto x : ans) cout << x << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}