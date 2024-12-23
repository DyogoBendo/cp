#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n);

        for (int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> colors(n, -1);

        stack<pair<int, int>> s;
        s.push({0, 0});

        int zero = 0;

        while(!s.empty()){
            auto p = s.top();
            s.pop();
            int curr = p.first, color = p.second;            

            if(colors[curr] != -1) continue;

            if(color == 0) zero ++;

            colors[curr] = color;

            for (auto v : graph[curr])
            {
                if(colors[v] == -1) s.push({v, color ^ 1});
            }
            
        }
        
        if(zero > n / 2) cout << n - zero;
        else cout << zero;
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            if(zero > n / 2){
                if(colors[j] == 1) cout << j + 1 << " ";
            } else{
                if(colors[j] == 0) cout << j + 1 << " ";
            }
        }
        cout << endl;
        
        
    }
    
}