#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;

    vector<int> colors(n, -1);
    vector<vector<int>> graph(n);
    for (int i = 0; i < n  - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    stack<pair<int, int>> s;
    s.push({0, 0});
    int w = 0;
    int current = 0;
    while(!s.empty()){
        auto p = s.top();
        int node = p.first, color = p.second ^ 1;

        s.pop();
        if(colors[node] != -1) continue;

        colors[node] = color;

        if(color == 0) w ++;

        for (auto v : graph[node])
        {
            s.push({v, color});
        }
        
    }    
    
    cout << (w) * (n - w) - (n - 1) << endl;
}