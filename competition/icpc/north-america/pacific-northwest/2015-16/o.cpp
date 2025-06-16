#include <bits/stdc++.h>

using namespace std;

#define int long long

const int SZ = 501;

int matrix[SZ][SZ];

int n, m;

signed main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {            
            matrix[i][j] = s[j] - '0';
        }        
    }    
    
    vector<vector<vector<pair<int, int>>>> graph(n, vector<vector<pair<int, int>>>(m));
    int x_move[] = {1, 0, -1, 0};
    int y_move[] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int x = i + (matrix[i][j] * x_move[k]);
                int y = j + (matrix[i][j] * y_move[k]);
                if(x >= 0 && x < n && y >= 0 && y < m){
                    graph[i][j].push_back({x, y});
                }
            }                    
        }                
    }
    
    vector<vector<int>> visited(n, vector<int>(m, 0));

    priority_queue<tuple<int, int, int>> pq;

    pq.push({0, 0, 0});

    while(!pq.empty()){
        auto curr = pq.top(); pq.pop();

        int dst= - get<0>(curr);
        int i= get<1>(curr);
        int j= get<2>(curr);
    
        if(visited[i][j]) continue;
        visited[i][j] = dst;

        for (auto u : graph[i][j])
        {            
            pq.push({-(dst + 1), u.first, u.second});
        }                
    }

    if(!visited[n - 1][m - 1]){
        cout << "IMPOSSIBLE" << endl;
    } else{
        cout << visited[n - 1][m - 1] << endl;
    }
    
}