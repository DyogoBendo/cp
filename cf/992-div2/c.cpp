#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;

void solve(){
    cin >> n >> k;
    vector<int> ans(n);
    k--;

    int l = 0;
    int r = n - 1;
    bool possible = true;
    for (int i = 1; i < n; i++)
    {
        int p = n - i - 1;

        if(p > 60 || 1LL << p > k){
            ans[l] = i;
            l ++;
        } else{
            k -= 1LL << p;
            ans[r] = i;
            r --;
        }
    }

    if(k){
        cout << -1 << endl;
        return;
    }
    ans[l] = n;
    
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}