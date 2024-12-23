#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> entries;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        entries.push_back({a, 1});
        entries.push_back({b, -1});
    }

    sort(entries.begin(), entries.end());
    
    int ans= 0;
    int current = 0;
    for (auto entry: entries)
    {
        current += entry.second;
        ans = max(ans, current);
    }
    
    cout << ans << endl;
}