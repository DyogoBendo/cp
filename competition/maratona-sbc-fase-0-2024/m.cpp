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

signed main(){
    fastio;
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int>> conn (n+1);
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }

    int max_dist=0;
    queue<int> q;
    for (int i=1; i<=n; i++){
        vector<int> dis (n+1, 2e5);
        q.push(i);
        dis[i]=0;
        while (!q.empty()){
            int x = q.front(); q.pop();
            for (auto c: conn[x]){
                if (dis[c] != 2e5) continue;
                q.push(c);
                dis[c] = dis[x] + 1;
            }
        }
        for (int j=1; j<=n; j++) max_dist = max(max_dist, dis[j]);
    }

    cout << max(0, 2*d+1 - max_dist) << ' ' << max(0, 2*d+1 - max_dist) << '\n';
}