#include<bits/stdc++.h>

using namespace std;

int visited[2 * 100000];
long long possibilities[2 * 100000];    

void build(vector<vector<int>> &graph, int i){
    int p = 0;    
    for (auto v : graph[i])
    {        
        if(!visited[v]){    
            visited[v] = 1;        
            build(graph, v);
            p += possibilities[v];
        }
    }
    possibilities[i] = max(1, p);
    
}

int main(){
    int t, n;
    cin >> t;
    while(t){
        t --;
        cin >> n;

        vector<vector<int>> graph (n); 
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a --;
            b --;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }        
        
        visited[0] = 1;
        build(graph, 0);        
        
        int q;
        cin >> q;

        for (int i = 0; i < q; i++)
        {
            int a, b;
            cin >> a >> b;
            a --;
            b --;
            cout << possibilities[a] * possibilities[b] << endl;
        }

        memset(visited, 0, sizeof(visited));
        memset(possibilities, 0, sizeof(possibilities));
        
    }
}