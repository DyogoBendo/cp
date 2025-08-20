#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    //darvem;

    int n, k;
    cin >> n >> k;

    vector<set<int>> v(k);
    for(int i = 0; i <n; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        v[a].insert(b);
        v[b].insert(a);
    }
    vector<int> in(k), visited(k);
    vector<vector<int>> g(k);
    for(int i = 0; i < k; i++){
        for(auto x : v[i]){
            g[i].push_back(x);
        }  
    }

    bool possible = true, cycle = false;
    int components = 0;
    vector<int> nonleaf(k);

    function<void(int, int)> dfs = [&](int curr, int p){
        int children = 0;
        if(visited[curr]){
            return;
        }
        visited[curr] = components;
        for(auto e : g[curr]){
            children++;
            dfs(e, curr);
        } 
        nonleaf[curr] = children > 1;
        return;
    };

    for(int i = 0; i < k; i++){
        if(g[i].size() && !visited[i]){
            components ++;
            dfs(i, i);
        }
    }

    vector<int> cntv(components+1), cnte(components+1);
    for(int i = 0; i < k; i++){
        if(!visited[i]) continue;
        int cnt = 0;
        if(nonleaf[i]){
            cntv[visited[i]] ++;
            for(auto e : g[i]){
                if(e == i ) continue;
                if(nonleaf[e]){
                    cnt++;
                    cnte[visited[i]]++;
                }
            }
            if(cnt > 2) possible = false;
        } 
    }
    for(int i = 1; i <= components; i++){
        if(cntv[i] == 0) continue;
        if(cnte[i] == 2*cntv[i]) cycle = true;
    }
    
    if(components > 1 and cycle) possible =false;

    cout << (!possible ? "impossible" : "possible") << endl;
}