#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
int visited[100000];

long double dfs(int curr, int p){
    if(visited[curr]) return 0;

    visited[curr] = 1;

    long double ans = 0;
    int qtd = 0;
    for (auto v : graph[curr])
    {
        if(!visited[v]){
            ans += dfs(v, p + 1);
            qtd ++;
        }
    }

    if(qtd == 0) return p;
    return ans / qtd;
}

int main(){
    int n;
    cin >> n;

    graph.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    
    printf("%.15Lf\n", dfs(0, 0));
    
}