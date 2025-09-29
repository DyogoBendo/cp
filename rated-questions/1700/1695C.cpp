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
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];

    int tot = (n+m-1);
    if(tot%2){
        cout << "NO" << endl;
        return;
    }

    vector<vector<pair<int, int>>> ans(n, vector<pair<int, int>>(m));
    vector<vector<int>> visited(n, vector<int>(m));

    function<pair<int, int>(int, int)> dfs = [&](int x, int y){
        if(visited[x][y]) return ans[x][y];
        visited[x][y] = 1;
        int k = grid[x][y] == 1;
        int l = k, l1 = 1e9, l2 = 1e9;
        int r = k, r1 = 0, r2 =0;
        bool found = false;
        if(x < n - 1){
            found = true;
            auto b = dfs(x+1, y);
            l1 = b.first + k;
            r1 = b.second + k;
        }
        if(y < m - 1){
            found = true;
            auto t = dfs(x, y+1);
            l2 = t.first + k;
            r2 = t.second + k; 
        }
        if(found) l = min(l1, l2), r = max(r1, r2);
        return ans[x][y] = make_pair(l, r);
    };

    auto a = dfs(0, 0);
    cout << (a.first <= tot/2 and a.second >= tot/2 ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}