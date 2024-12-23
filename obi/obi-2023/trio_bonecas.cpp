#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e4 + 1;
const int MAXK = MAXN * (1e3 + 1);
const int INF = MAXK * MAXK;
int dp[MAXN];
int dp_prev[MAXN];
int n, k;

void troca(){
    for (int i = 0; i < n; i++)
    {
        dp_prev[i] = dp[i];
    }
    
}

signed main(){
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
        dp_prev[i] = INF;
    }

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < 3 * (i) - 1; j++)
        {
            dp[j] = INF;
        }

        for (int j = 3 * (i) - 2 ; j < n ; j++)
        {
            if(j == 1){
                dp[j] = v[j] - v[j - 1];
            } else{
                int a = v[j] - v[j - 1];
                dp[j] = min(dp[j - 1], dp_prev[j - 2] + a * a);
            }
        }
        troca();
    }

    int ans = INF;

    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, dp[i]);
    }
    
    cout << ans << endl;

}