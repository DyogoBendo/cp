#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

struct P{
    ll x, y;
};

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 2e5 + 1;

vector<vector<pair<int, int>>> conn (MAXN);
vector<int> visited (MAXN);

void dfs(int x, int t){
    visited[x] = 1;
    for (auto [c, w]: conn[x]){
        if (visited[c]) continue;
        if (w > t) continue;
        dfs(c, t);
    }
}

signed main(){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        conn[a].push_back({b, w});
        conn[b].push_back({a, w});
    }

    int l=0, r=8760, ans=0;
    while (l <= r){
        int m = l + (r-l)/2;
        dfs(1, m);
        int ctr=0;
        for (int i=1; i<=n; i++){
            if (visited[i]) ctr++;
            visited[i] = 0;
        }

        if (ctr >= k){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }

    cout << ans << '\n';
}