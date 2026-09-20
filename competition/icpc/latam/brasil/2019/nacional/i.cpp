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

const int MOD = 1e9 + 7;

signed main(){
    darvem;
    int n, l;
    cin >> n >> l;

    vector<vector<int>> g(n);
    for(int i =0;i < l; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int u;
            cin >> u;
            u--;
            g[i].push_back(u);
        }
    }
    
    vector<int> visited(n);
    vector<int> dp(n);
    function<int(int)> dfs = [&](int curr){
        if(visited[curr]) return dp[curr];
        
        visited[curr] = 1;
        if(curr >= l) return dp[curr] = 1;
        int tot = 0;
        for(auto v : g[curr]) tot = (tot + dfs(v)) % MOD;        
        return dp[curr] = tot;
    };

    cout << dfs(0) << " ";
    int cnt_visited = 0;
    for(int i = l; i < n; i++) cnt_visited += visited[i];
    cout << cnt_visited << endl;
}