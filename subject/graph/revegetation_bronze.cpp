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
    
    vector<vector<int>> graph(n);
    vector<int> used(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> av(5, 1);
        for (auto u : graph[i])
        {            
            av[used[u]] = 0;            
        }

        for (int j = 1; j <= 4; j++)
        {
            if(av[j]){
                cout << j;
                used[i] = j;
                break;
            }
        }
        
    }
    cout << endl;

}