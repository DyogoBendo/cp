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
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> distances(n+1);
    vector<int> parv(n+1);
    vector<int> first_child(n+1);
    map<int, set<int>> parents;

    function<void(int, int, int)> dfs = [&](int curr, int p, int d){
        distances[curr] = d;
        parents[d].insert(p);
        parv[curr] = p;
        for(auto e : g[curr]) if(e != p){
            first_child[curr] = e;
            dfs(e, curr, d+1);
        }
    };

    dfs(1, 1, 1);

    vector<vector<int>> dgroup(n+1), d2(n+1);
    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(first_child[i]) d2[distances[i]].push_back(i);
        else dgroup[distances[i]].push_back(i); 
        ans = max(ans, sz(dgroup[distances[i]]) + sz(d2[distances[i]]) + (sz(parents[distances[i]]) == 1));
    }
        
    cout << ans << endl;


    vector<int> depths;
    for(int i = n; i >=0 ; i--) if(sz(dgroup[i])){
        depths.push_back(i);
    }

    vector<int> g2(n+1);

    vector<int> st;
    
    vector<int> cnt(n+1);
    for(int i = 1; i <= n; i++){
        if(sz(d2[i]) == 1) continue;
        for(int j = 0; j < sz(d2[i]); j++){
            int prox = (j + 1) % (sz(d2[i]));

            g2[first_child[d2[i][j]]] = d2[i][prox];
            cnt[d2[i][prox]]++;
        }
    }

    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0 && g2[i]) st.push_back(i);
    }

    set<int> ap;
    for(auto s : st){
        ans--;
        int x = s;
        vector<int> curr_ans;
        while(x){
            ap.insert(x);
            curr_ans.push_back(x);
            x = g2[x];
        }

        if(sz(curr_ans) == 0) continue;

        cout << sz(curr_ans);
        for(auto u : curr_ans) cout << " " << u;
        cout << endl;
    }

    vector<int> tmp2;
    for(int d : depths){
        vector<int> tmp3;
        for(auto x : dgroup[d]){
            if(ap.find(x) == ap.end()) tmp3.push_back(x);
        }
        dgroup[d] = tmp3;

        if(sz(tmp3)) tmp2.push_back(d);
    }
    depths = tmp2;

    while(ans > 0){
        vector<int> tmp;

        int par = -1;
        vector<int> curr_ans;
        for(int d : depths){
            int lst = dgroup[d].back();
            if(sz(dgroup[d]) == 1 && lst == par ){ // so tem ele e é pai de alguém
                tmp.push_back(d);
                continue;
            } else if(lst == par){
                dgroup[d].pop_back();
                int curr_x = dgroup[d].back();

                curr_ans.push_back(curr_x);
                par = parv[curr_x];
                dgroup[d].pop_back();

                dgroup[d].push_back(lst);
            } else{
                curr_ans.push_back(lst);
                par = parv[lst];
                dgroup[d].pop_back();
            }

            if(sz(dgroup[d]) >= 1) tmp.push_back(d);
        }   

        if(sz(curr_ans) != 0){
            cout << sz(curr_ans);
            for(auto u : curr_ans) cout << " " << u;
            cout << endl;
        }

        depths = tmp;
    }



}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}