#include <bits/stdc++.h>

using namespace std;

#define int long long 

signed main(){
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    int ans = 0;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        ans += tasks[i].second - tasks[i].first - time;
        time += tasks[i].first;
    }
    

    cout << ans << endl;
    
}