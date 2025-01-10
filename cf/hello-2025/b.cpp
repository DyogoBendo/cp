#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve(){
    int n, k;
    cin >> n >> k;

    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x] ++;
    }    

    vector<int> qt;

    for (auto x : m)
    {
        qt.push_back(x.second);
    }
    int ans = qt.size();    

    sort(qt.begin(), qt.end());

    // cout << "ans: " << ans << endl;

    for (int i = 0; i < qt.size(); i++)
    {
        //cout << "k: " << k << endl;
        if(qt[i] > k) break;
        else{
            k -= qt[i];
            ans --;
        }
    }
    
    ans = max(ans, 1);

    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}