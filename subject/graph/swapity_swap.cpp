#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int dfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &idx, int curr){
    if(visited[curr]) return 0;
    visited[curr] = 1;        

    idx.push_back(curr);

    int t = 1;
    for (auto u : graph[curr])
    {        
        t += dfs(graph, visited, idx, u);
    }

    return t;
}


int main(){
     setIO("swap");

    int n, k;
    cin >> n >> k;

    vector<vector<int>> graph(n);
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = i;
        b[i] = i;
    }
    

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    a1--; b1--;a2--;b2--;

    for (int i = 0; i < (b1 - a1 + 1) /2; i++)
    {
        swap(a[a1 + i], a[b1 - i]);
        graph[a1 + i].push_back(b1 - i);
        graph[b1 - i].push_back(a1 + i);
    }
    for (int i = 0; i < (b2 - a2 + 1) /2; i++)
    {
        swap(b[a2 + i], b[b2 - i]);
        graph[a2 + i].push_back(b2 - i);
        graph[b2 - i].push_back(a2 + i);
    }

    vector<int> visited(n, 0);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = i + 1;
    }
    

    for (int i = 0; i < n; i++)
    {        
        if(visited[i]) continue;                

        vector<int> idx;

        int sz = dfs(graph, visited, idx, i);        

        int x = k % sz;        

        while(x--)
        {
            for (auto y : idx)
            {                       
                if(y < a[y])swap(ans[y], ans[a[y]]);                
            }       
            for (auto y : idx)
            {                                
                if(y < b[y]) swap(ans[y], ans[b[y]]);
            }             
            
        }        
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    
}