#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph (n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> graph[i][j];
            }
            
        }

        vector<vector<int>> visited (n, vector<int>(m, 0));

        int max_v = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {                
                if(visited[i][j]) continue;
                if(!graph[i][j]) continue;

                int current_max = 0;
                stack<pair<int, int>> s;
                s.push({i, j});
                while(!s.empty()){                    
                    auto current = s.top();                    
                    s.pop();

                    if(current.first >= 0 && current.first < n 
                        && current.second >= 0 && current.second < m 
                        && !visited[current.first][current.second]
                        && graph[current.first][current.second]){
                        current_max += graph[current.first][current.second];
                        visited[current.first][current.second] = 1;

                        s.push({current.first + 1, current.second});
                        s.push({current.first - 1, current.second});
                        s.push({current.first, current.second + 1});
                        s.push({current.first, current.second - 1});
                    }
                }

                max_v = max(max_v, current_max);
            }
            
        }

        cout << max_v << endl;
        
    }
}