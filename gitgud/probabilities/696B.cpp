#include <bits/stdc++.h>

using namespace std;

int n;
int dfs1(vector<int> &v, vector<vector<int>> &g, int curr){        
    int ans = 1;
    for (auto c : g[curr])
    {
        ans += dfs1(v, g, c);
    }

    v[curr] = ans;
    
    return ans;
}

void dfs2(vector<vector<int>> &g, vector<int> &v, vector<double> &a, int curr, double p){
    double ans = (p + 1) + (n - p - v[curr]) / 2 ;        

    a[curr] = ans;

    for (auto c : g[curr])
    {
        dfs2(g, v, a, c, p + 1);
    }
    
}

void solve(){
    cin >> n;

    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int p;
        cin >> p;

        p --;
        graph[p].push_back(i + 1);
    }    

    vector<int> children(n, 0);
    vector<double> ans(n, 0);
    dfs1(children, graph, 0);
    dfs2( graph, children, ans, 0, 0);

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    
}

signed main(){
    int t;
    t = 1;

    while(t--) solve();
}