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

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<int> ssize(n), par(n);

    int pos_meio = -1;
    
    function<void(int, int)> dfs = [&](int curr, int p){
        for(auto u : g[curr]) if(u != p) dfs(u, curr);
        
        par[curr] = p;        
        int size = 1;
        for(auto u : g[curr]) if(u != p) size += ssize[u];

        if(2*size == n)  pos_meio = curr;

        ssize[curr] = size;
    };

    dfs(0, 0);

    function<void(int, int, int, vector<int>&)> dfs_dis = [&](int curr, int p, int d, vector<int>&cnt){
        if(d == cnt.size()) cnt.push_back(0);
        cnt[d]++;
        for(auto u : g[curr]) if(u != p) dfs_dis(u, curr, d+1, cnt);        
    };

    ll ans = 0;

    if(pos_meio != -1){
        vector<int> c1, c2;
        dfs_dis(pos_meio, par[pos_meio], 0, c1);
        dfs_dis(par[pos_meio], pos_meio, 0, c2);

        for(int i = 0; i < min(sz(c1), sz(c2)); i++) ans += 1LL * c1[i] * c2[i];        
    }

    for(int u = 0; u < n; u++){
        vector<pair<int, int>> branches;

        for(int v : g[u]) branches.emplace_back(v == par[u] ? n - ssize[u] : ssize[v], v);

        sort(branches.begin(), branches.end());

        for(int i = 0; i < sz(branches); ){
            int j = i;
            vector<vector<int>> all_cnt;
            int mx_depth = 0;
            while(j < sz(branches) and branches[i].first == branches[j].first) j++;

            int tam = j - i;
            if(tam < 2) goto end_loop;

            for(int k = i; k < j; k++){
                vector<int> c;
                dfs_dis(branches[k].second, u, 0, c);
                mx_depth = max(mx_depth, sz(c));
                all_cnt.push_back(c);
            }

            for(int d = 0; d < mx_depth; d++){
                ll sum_sq = 0, sum = 0;
                for(int k = 0; k < tam; k++){
                    if(sz(all_cnt[k]) > d){
                        ll s = all_cnt[k][d];
                        sum_sq += s*s;
                        sum += s;
                    } 
                }
                ans += ((sum * sum) - sum_sq) / 2;
            }

            end_loop:
            i = j;
        }
    }

    cout << ans << endl;

}