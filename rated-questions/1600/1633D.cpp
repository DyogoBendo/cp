#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXN = 1e3+10;

int dp_op[MAXN];

void init(){
    for (int i = 0; i < MAXN; i++)
    {
        dp_op[i] = MAXN;
    }
    dp_op[0] = 0;
    dp_op[1] = 0;

    for (int i = 1; i < MAXN; i++)
    {        
        for (int j = 1; j <= i; j++)
        {            
            if(i+i/j < MAXN) dp_op[i+i/j] = min(dp_op[i+i/j], dp_op[i]+1);
        }        
    }
    
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> b(n), c(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] = dp_op[b[i]];
        mx += b[i];
    }

    mx = min(mx, k);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    vector<int>dp(mx+1, 0);    
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = mx; j >= 0; j--)
        {
            if(j + b[i] <= mx) dp[j+b[i]] = max(dp[j+b[i]], dp[j] + c[i]);
        }        
    }    
    for (int i = 0; i <=mx; i++)
    {
        ans = max(ans, dp[i]);
    }


    cout << ans << endl;

}


signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}