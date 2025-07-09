#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, c, s;
    cin >> n >> c >> s;

    vector<vector<int>> graph(n);

    for (int i = 0; i < c; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b); graph[b].push_back(a);
    }

    vector<pair<int, int>> soldiers(s + 1);

    for(int i = 1; i <= s; i++) cin >> soldiers[i].first >> soldiers[i].second;
    
    vector<int> visited(n);

    bool possible = true;
    function<void(int, int, int)> dfs = [&](int soldier, int room, int d){
        if(visited[room]){
            if(visited[room] != soldier) possible = false;
            return;
        }
        visited[room] = soldier;
        if(d == 0) return;

        for (auto e : graph[room])
        {
            dfs(soldier, e, d-1);
        }
    };

    for (int i = 1; i <= s; i++)
    {
        dfs(i, soldiers[i].first - 1, soldiers[i].second);
    }

    for(int i = 0; i < n; i++) if(!visited[i]) possible = false;

    cout << (possible? "Sim" : "Nao") << endl;
}