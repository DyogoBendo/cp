#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("revegetate");

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    vector<int> color(n, -1);    
    for (int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;

        a--;
        b--;
        if(c == 'S'){
            graph[a].push_back({b, 0});
            graph[b].push_back({a, 0});
        } else{
            graph[a].push_back({b, 1});
            graph[b].push_back({a, 1});
        }
    }
    

    int possible = 1, k = 0;
    for (int i = 0; i < n; i++)
    {
        if(color[i] == -1){
            k ++;
            stack<pair<int, int>> s;
            s.push({i, 0});

            while(!s.empty()){
                int curr, c;
                auto p = s.top();
                s.pop();
                curr = p.first;
                c = p.second;                

                if(color[curr] == - 1){
                    color[curr] = c;
                } else if(color[curr] != c){
                    possible = 0;
                    continue;
                } else{
                    continue;
                }

                for (auto v : graph[curr])
                {
                    if(v.second == 0){
                        s.push({v.first, c});
                    } else{
                        s.push({v.first, c ^ 1});
                    }
                }
                
            }
        }
    }

    if(possible == 0) cout << 0 << endl;
    else{
        cout << 1;

        for (int i = 0; i < k; i++)
        {
            cout << 0;
        }
        cout << endl;
    }
        
}