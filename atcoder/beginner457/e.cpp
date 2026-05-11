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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(m);
    for(int i = 0; i < m; i++) cin >> v[i].first >> v[i].second;

    map<pair<int, int>, int> cnt;
    for(int i = 0; i < m; i++) cnt[v[i]]++;

    int q;
    cin >> q;    
    vector<tuple<int, int, int>> queries;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }    

    vector<int> ans_l(q), ans_r(q);        
    vector<vector<pair<int, int>>> lg(n+1);
    for(int i = 0; i < m; i++){
        lg[v[i].first].push_back({v[i].second, i});
    }

    for(int i = 0; i <= n; i++){
        sort(lg[i].begin(), lg[i].end());
    }

    vector<vector<pair<int, int>>> rg(n+1);
    for(int i = 0; i < m; i++){
        rg[v[i].second].push_back({v[i].first, i});
    }

    for(int i = 0; i <= n; i++){
        sort(rg[i].rbegin(), rg[i].rend());
    }

    int prev = -1;
    int pos = -1;
    sort(queries.begin(), queries.end());
    for(int i = 0; i < q; i++){
        auto [l, r, idx] = queries[i];        

        if(l != prev){
            pos = 0;            
        }
        if(lg[l].empty()){
            ans_l[idx] = -1;
        } else{
            if(lg[l][0].first > r) ans_l[idx] = -1;
            else{
                while(pos+1 < sz(lg[l]) and lg[l][pos+1].first <= r) pos++;            
                dbg(l, lg[l][pos].first, lg[l][pos].second);
                ans_l[idx] = lg[l][pos].second;
            }
        }
        
        prev = l;
    }    

    prev = -1;
    pos = -1;
    sort(queries.rbegin(), queries.rend());
    for(int i = 0; i < q; i++){
        auto [l, r, idx] = queries[i];

        if(r != prev){
            pos = 0;            
        }
        if(rg[r].empty()){
            ans_r[idx] = -1;
        } else{
            if(rg[r][0].first < l) ans_r[idx] = -1;
            else{
                while(pos+1 < sz(rg[r]) and rg[r][pos+1].first >= l) pos++;            
                ans_r[idx] = rg[r][pos].second;
            }
        }
        
        prev = r;
    }

    vector<tuple<int, int, int, int>> v2;
    for(int i = 0; i < m; i++) v2.push_back({v[i].first, -v[i].second, i, 0}), v2.push_back({v[i].second, -v[i].first, i, 1});

    sort(v2.begin(), v2.end());

    vector<int> nested(m, -1);
    set<pair<int, pair<int, int>>> st;
    for(auto [l, r, idx, op] : v2){
        r = -r;
        if(op == 1) swap(l, r);        

        dbg(l, r, idx, op);
        if(op == 0){
            st.insert({l, {-r, idx}});
        } else{
            st.erase({l, {-r, idx}});
            while(!st.empty()){
                if(st.begin()->first <= l){                    
                    nested[st.begin() ->second.second] = idx;                    
                    st.erase(st.begin());
                } else break;
            }
        }                
    }

    for(int i = 0; i < q; i++){
        if(ans_l[i] == -1 or ans_r[i] == -1){
            cout << "No" << endl;
        } else{
            int il = ans_l[i];
            int ir = ans_r[i];            

            if(il == ir){                
                if(nested[il] != -1 or cnt[v[il]] > 1){
                    cout << "Yes" << endl;
                } else cout << "No" << endl;
            } else if(v[il].second >= v[ir].first-1){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        }
    }

}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}