#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> visited;

int ans = 0;

int solve(int curr){
    if(visited[curr]) return 0;

    visited[curr] = 1;

    int a1 = 0;
    int a2 = 0;

    for (auto v: g[curr])
    {
        int b = solve(v);

        if(b > a1){
            a2 = a1;
            a1 = b;            
        } else{
            a2 = max(b, a2);
        }
    }

    cout << "curr: " << curr + 1<< " a1: " << a1 << " a2: " << a2 << endl;

    ans = a1 + a2;

    return a1 + 1;
    
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

    solve(0);
    cout << ans << endl;
    
}