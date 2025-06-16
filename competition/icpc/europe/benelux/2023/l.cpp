#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n), gi(n);    

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        a--; b--;

        g[b].push_back(a);
        gi[a].push_back(b);
    }

    vector<int> v1(n), v2(n);
    vector<int> ord;

    function<void(int)> dfs1 = [&](int curr){
        if(v1[curr]) return;
        v1[curr] = 1;

        for (auto e : g[curr])
        {
            dfs1(e);
        }
        ord.push_back(curr);
    };
    for (int i = 0; i < n; i++)
    {
        dfs1(i);
    }
    reverse(ord.begin(), ord.end());


    int total = 0;
    vector<int> comp(n);
    function<void(int)> dfs2 = [&](int curr){
        if(v2[curr]) return;
        v2[curr] = 1;

        for (auto e : gi[curr])
        {
            dfs2(e);
        }
        comp[curr] = total;
    };

    for (auto x : ord)
    {
        if(!v2[x]) total++;
        dfs2(x);
    }

    int ans = 0;
    vector<int> cnt(total);
    for (int i = 0; i < n; i++)
    {        
        for (auto e : g[i])
        {
            if(comp[e] != comp[i]){
                cnt[comp[i]-1] ++;
            }
        }        
    }
    
    for (int i = 0; i < total; i++)
    {
        ans += cnt[i] == 0;
    }
    
    cout << ans << endl;

}