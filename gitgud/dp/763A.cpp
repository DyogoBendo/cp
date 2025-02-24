#include <bits/stdc++.h>

using namespace std;

vector<int> colors;
vector<vector<int>> g;
vector<int> subtree_color;
vector<int> ans;

int dfs1(int curr, int p){
    int c = colors[curr];

    for (auto u : g[curr])
    {
        if(u != p){
            int cc = dfs1(u, curr);
            if(c != cc) c = 0;
        }
    }
    
    subtree_color[curr] = c;
    return c;
}

void dfs2(int curr, int p, int p_color){
    if(p_color == 0) return;

    // cout << "curr: " << curr << " p: " << p << " pcolor: " << p_color << " current color " << colors[curr] << endl;

    int not_qual = 0;
    int id = -1;
    for (auto u : g[curr])
    {
        if(u == p) continue;
        if(!subtree_color[u]){
            // cout << "u: " << u << endl;
            not_qual ++;        
            id = u;
        } 
    }

    if(not_qual == 0) ans.push_back(curr);
    else if(not_qual == 1){
        int all_equal = p_color == colors[curr];
        // cout << "aqui " << all_equal << endl;
        for (auto u : g[curr])
        {
            if(u == p) continue;
            if(u != id && colors[u] != colors[curr]) all_equal = 0;
        }
        
        if(all_equal) dfs2(id, curr, colors[curr]);
    }

}

void solve(){
    int n;
    cin >> n;
    colors.resize(n);
    g.resize(n);
    subtree_color.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i];
    }
    
    dfs1(0, -1);
    dfs2(0, -1, colors[0]);

    if(ans.size()) cout << "YES" << endl << ans[0] + 1 << endl;
    else cout << "NO" << endl;    

}

signed main(){
    int t;
    t = 1;

    while(t--) solve();
}