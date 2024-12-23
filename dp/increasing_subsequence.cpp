#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        v2[i] = x;
    }

    sort(v2.begin(), v2.end());

    map<int, int> m;

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if(m.find(v2[i]) == m.end()){
            c++;
            m.insert({v2[i], c});
        }
    }
    

    vector<int> dp(n + 1, 1e9 + 2);
    dp[0] = 0;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = m[v[i]];
        auto p = lower_bound(dp.begin(), dp.end(), curr);

        *p = curr;
        int x = distance(dp.begin(), p);
        ans = max(ans, x);
    }
    
    cout << ans << endl;
}