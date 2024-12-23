#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v (n);
    for(auto &c : v) cin >> c;

    vector<int> dp;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        dp.push_back(1);
        for (int j = i - 1; j >= max(i - 512, 0); j--)
        {            
            if((v[j] ^ i) < (v[i] ^ j)){                
                dp[i] = max(dp[i], dp[j] + 1);
            }            
        }

        ans = max(ans, dp[i]);
        
    }

    cout << ans << endl;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();

}