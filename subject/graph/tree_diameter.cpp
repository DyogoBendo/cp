#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> visited;

pair<int, int> bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, 0});

    int i = -1, ma = -1;

    while(!q.empty()){
        auto f = q.front(); q.pop();

        int c = f.first, d = f.second;


        if(visited[c]) continue;

        visited[c] = 1;

        if(d > ma){
            ma = d;
            i = c;
        }


        for (auto v: g[c])
        {
            q.push({v, d + 1});
        }
        

    }
    fill(visited.begin(), visited.end(), 0);

    return {i, ma};
}

int main(){
    int n;
    cin >> n;
    g.resize(n);
    visited.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int start = bfs(0).first;

    cout << bfs(start).second << endl;
    
}