#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> t(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    vector<int> visited(n, 0);
    vector<int> color(n, 0);
    int colorA = 0, colorB = 0;

    function<void(int, int, int)> dfs = [&](int curr, int p, int c){
        if(visited[curr]) return;
        visited[curr] = 1;
        color[curr] = c;
        if(c) colorA ++;
        else colorB ++;
        for (auto u : t[curr])
        {
            if(u == p) continue;
            dfs(u, curr, (c + 1) % 2);
        }        
    };

    dfs(0, 0, 0);

    int ans = 0;    
    for (int i = 0; i < n; i++)
    {
        if(color[i]) continue;
        int sz = t[i].size();                
        ans += colorA - sz;
    }
    cout << ans << endl;

}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}