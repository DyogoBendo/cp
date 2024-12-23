#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXN = 5e5 + 10;

int psum[MAXN];

int dfs(vector<vector<int>> &graph, int p, int v, int d){
    int begin = d, end = d;    
    
    for (auto u : graph[v])
    {
        if(u != p){
            end = max(dfs(graph, v, u, d + 1), end);            
        }
    }    

    psum[begin] ++;
    psum[end + 1] --;

    return end;    
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }    
    
    dfs(graph, -1, 0, 0);

    int ans = MAXN;
    int s = 0;    
    for (int i = 0; i <= n; i++)
    {
        s += psum[i];
        int x = n - s;
        ans = min(x, ans);
        psum[i] = 0;
    }

    cout << ans << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}