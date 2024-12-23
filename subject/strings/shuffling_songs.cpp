#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<pair<string, string>> elements;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        elements.push_back({a, b});
    }

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++)
    {
        auto e1 = elements[i];
        for (int j = i + 1; j < n; j++)
        {
            auto e2 = elements[j];
            if(e1.first == e2.first || e1.second == e2.second){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }        
    }
    
    vector<int> visited(n, 0);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        int count = 1;
        visited[i] = 1;
        stack<int> s;
        s.push(i);
        while(!s.empty()){
            int current = s.top();
            s.pop();

            for (auto e: graph[current])
            {
                if(e && !visited[e]){
                    visited[e] = 1;
                    count ++;
                    s.push(e);
                }
            }
            
        }
        
        ans= max(ans, count);
    }
    
    cout << n - ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}