#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

#define int long long

signed main(){
    setIO("mountains");
    int n;
    cin >> n;

    vector<pair<int, int>> mountains;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        mountains.push_back({x - y, x + y});
    }
    
    sort(mountains.begin(), mountains.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    int current_end = 0;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(mountains[i].second > current_end){
            current_end = mountains[i].second;
            ans ++;
        }
    }

    cout << ans << endl;
    
}