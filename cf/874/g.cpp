#include <bits/stdc++.h>

using namespace std;


int dfs(vector<vector<pair<int, int>>> &graph, vector<int> &visited, int current, vector<int> &answer){
    int children = 0;    
    for (auto u : graph[current])
    {
        if(!visited[u.first]){
            visited[u.first] = 1;
            int c = dfs(graph, visited, u.first, answer);            
            if(c == 0){                
                answer.push_back(u.second);
            }
            children += c;
        }
    }

    if(children == 2){
        return children - 2;
    }
     else{
        return children + 1;
    }
}

int main(){
    int t;
    cin >> t;
    while(t --){        
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> graph(n); 
        vector<int> visited(n);      
        vector<int> answer;        
        for (int i = 0; i < n - 1; i++)
        {                        
            int v, u;
            cin >> v >> u;
            v --;
            u --;            
            graph[u].push_back({v, i + 1});
            graph[v].push_back({u, i + 1});
        }        
        
        if(n % 3){            
            cout << -1 << endl;
            continue;
        }
        

        visited[0] = 1;
        int r = dfs(graph, visited, 0, answer);        
        if(r){
            cout << -1 << endl;
        } else{            
            cout << answer.size() << endl;
            for (auto a : answer)
            {
                cout << a << " ";
            }
            cout << endl;
            
        }

    }
}