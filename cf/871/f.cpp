#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph (n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u --;
            v --;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        multiset<int> ms;
        for (int i = 0; i < n; i++)
        {
            int qttd = graph[i].size();
            ms.insert(qttd);
        }

        int x, y;
        int equals = 1;

        for (int i = 0; i < n; i++)
        {
            int qttd = graph[i].size();
            if(qttd == 1) continue;
            if(ms.count(qttd) == 1){
                equals = 0;
                x = qttd;
            } else{
                y = qttd - 1;
            }            
        }

        if(equals) x = y + 1;
        
        cout << x << " " << y << endl;
        
    }
}