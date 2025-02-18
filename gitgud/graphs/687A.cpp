#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> &v, vector<vector<int>>&g, int curr){
    if(v[curr]) return;
    v[curr] = 1;

    for (auto e : g[curr])
    {
        dfs(v, g, e);
    }
    
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    queue<pair<int, int>> q;
    set<int> arya;
    set<int> pari;

    int k = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        k = max(a, b);
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            dfs(visited, graph, i);
            if(graph[i].size() == 0) continue;
            q.push({i, graph[i][0]});
        }
    }
    

    bool possible = true;
    while(!q.empty() && possible){
        auto [a, b] = q.front();
        q.pop();

        if(arya.count(a) && arya.count(b)){
            //cout << "a: " << a << " b: " << b << endl; 
            possible = false;
        } 
        if(pari.count(a) && pari.count(b)){
            //cout << "a1: " << a << " b: " << b << endl;
            possible = false;
        } 
        if((arya.count(a) && pari.count(b)) || (arya.count(b) && pari.count(a))) continue;
        
        if(arya.count(a)){
            pari.insert(b);
            for (auto e : graph[b])
            {
                q.push({b, e});
            }
        }
        else if(arya.count(b)){
            pari.insert(a);
            for (auto e : graph[a])
            {
                q.push({a, e});
            }
        } else if(pari.count(a)){
            arya.insert(b);
            for (auto e : graph[b])
            {
                q.push({b, e});
            }
        } else if(pari.count(b)){
            arya.insert(a);
            for (auto e : graph[a])
            {
                q.push({a, e});
            }
        } else{
            arya.insert(a);
            pari.insert(b);
            for (auto e : graph[a])
            {
                q.push({a, e});
            }
            for (auto e : graph[b])
            {
                q.push({b, e});
            }
        }
    }

    if(!possible){
        cout << -1 << endl;
    } else{
        cout << arya.size() << endl;
        for (auto a : arya)
        {
            cout << a + 1 << " ";
        }
        cout << endl;
        cout << pari.size() << endl;
        for (auto p : pari)
        {
            cout << p + 1 << " ";
        }
        cout << endl;
    }
}

signed main(){
    int t = 1;

    while(t--) solve();
}