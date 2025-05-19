#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

const int MAX = 1e3 + 10;
const ll MOD = 1e9+7;


ll dp[MAX][MAX]; // dp[n][k]
int n;

int go(int x, int k){    
    if(k <= 0) return 0;
    if(x <= 0) return 1;
 
    if(dp[x][k] != -1) return dp[x][k];
    return dp[x][k] = (go(x-1, k) + go(n-x, k-1)) % MOD;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int k;
    cin >> n >> k;    

    cout << go(n, k) << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}