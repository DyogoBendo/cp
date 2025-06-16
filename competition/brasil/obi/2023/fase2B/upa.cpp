#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> o;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        o.push_back({x, 1});
        o.push_back({y, -1});
    }

    sort(o.begin(), o.end());


    int atual = 0;

    int ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        atual += o[i].second;
        ans = max(ans, atual);
    }

    cout << ans * 20 << endl;
    
    
}