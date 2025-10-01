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

    vector<vector<pair<int, int>>> g(n+1);

    for(int i = 0; i < m; i++){
        int a, b;
        string s;
        cin >> a >> b >> s;

        int c = s == "imposter";

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    vector<int> visited(n+1, -1);
    bool possible = true;
    int cnt[2] = {0};
    function<void(int, int)> dfs = [&](int curr, int color){
        if(visited[curr] != -1){
            if(color != visited[curr]) possible = false;
            return;
        }
        cnt[color]++;
        visited[curr] = color;

        for(auto [u, c] : g[curr]){
            dfs(u, c ^ color);
        }

    };

    int ans = 0;
    for(int i = 1; i <=n; i++){
        if(visited[i] == -1){
            cnt[0] = cnt[1] = 0;
            dfs(i, 0);
            ans += max(cnt[0], cnt[1]);
        }
    }
    if(!possible) ans = -1;
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}