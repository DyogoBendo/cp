#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, k, a[N];

int dp[N], b[N];

bool check(int m){

    for (int i = 0; i < n; i++)
    {
        if(a[i] < m) b[i] = -1;
        else b[i] = 1;
    }
    
    dp[0] = b[0];

    for (int i = 1; i < n; i++)
    {
        if(i %k == 0){
            dp[i] = max(b[i], dp[i - k]);
        } else{
            dp[i] = dp[i - 1] + b[i];
            if(i > k){
                dp[i] = max(dp[i - k], dp[i]);
            }
        }
    }
    
    return dp[n - 1] > 0;
}

void solve(){
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    

    int lo = 1, hi = 1e9;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid)){
            lo = mid + 1;
        } else{
            hi = mid - 1;
        }
    }
    cout << hi << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}