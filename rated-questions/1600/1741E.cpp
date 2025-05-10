#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n+1);
    dp[0] = 1;

   for (int i = 1; i <= n; i++)
   {
        if(dp[i-1] && i + v[i] <= n){            
            dp[i+v[i]] = 1;
        } 
        if(i-v[i]-1 >= 0 && dp[i-v[i]-1]){            
            dp[i] = 1;
        } 
   }
   
   cout << (dp[n] ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}