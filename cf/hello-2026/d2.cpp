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
    map<int, set<int>> parents;

    function<void(int, int, int)> dfs = [&](int curr, int p, int d){
        distances[curr] = d;
        parents[d].insert(p);
        parv[curr] = p;
        for(auto e : g[curr]) if(e != p){
            dfs(e, curr, d+1);
        }
    };

    dfs(1, 1, 1);

    vector<vector<int>> dgroup(n+1);
    int ans = 0;

    for(int i = 1; i <= n; i++){
        dgroup[distances[i]].push_back(i);
        ans = max(ans, sz(dgroup[distances[i]]) + (sz(parents[distances[i]]) == 1));
    }
    vector<int> depths;
    for(int i = n; i >=0 ; i--) if(sz(dgroup[i])){
        depths.push_back(i);

        if(i % 2) reverse(dgroup[i].begin(), dgroup[i].end());
    }
    
    cout << ans << endl;
    while(ans--){
        vector<int> tmp;

        int prev = 1e8, par = -1;
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
                prev = curr_x;
                par = parv[curr_x];
                dgroup[d].pop_back();

                dgroup[d].push_back(lst);
            } else{
                curr_ans.push_back(lst);
                prev = lst;
                par = parv[lst];
                dgroup[d].pop_back();
            }

            if(sz(dgroup[d]) >= 1) tmp.push_back(d);
        }   

        cout << sz(curr_ans);
        for(auto u : curr_ans) cout << " " << u;
        cout << endl;

        depths = tmp;
    }

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}