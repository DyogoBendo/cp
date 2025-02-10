#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    vector<tuple<int, int, int, int>> vs;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v.push_back({a, b});
        vs.push_back({a, b, 0, i});
        vs.push_back({b, a, 1, i});
    }

    sort(vs.begin(), vs.end());

    for (int i = 0; i < 2 * n; i++)
    {
        auto [valor, pos, vizinho, grupo] = vs[i];
        if(visited[grupo]) continue;
        visited[grupo] = 1;

        cout << v[grupo].first << " " << v[grupo].second << " ";
    }
    
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}