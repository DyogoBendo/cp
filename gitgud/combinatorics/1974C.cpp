#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<tuple<int, int, int>, int> ms;
    map<pair<int, int>, int> s1;
    map<pair<int, int>, int> s2;
    map<pair<int, int>, int> s3;

    int ans = 0;

    for (int i = 0; i < n - 2; i++)
    {
        ms[{v[i], v[i + 1], v[i + 2]}]++;
        s1[{v[i + 1], v[i + 2]}]++;
        s2[{v[i], v[i + 2]}]++;
        s3[{v[i], v[i + 1]}]++;
    }
    
    for (auto k : ms)
    {
        auto [a1, a2, a3] = k.first;        
        int curr = k.second;
        int x1 = s1[{a2, a3}];
        int x2 = s2[{a1, a3}];
        int x3 = s3[{a1, a2}];
        
        ans += curr * (x1 - curr);
        ans += curr * (x2 - curr);
        ans += curr * (x3 - curr);
    }
    
    ans /= 2;

    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}