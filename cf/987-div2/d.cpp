#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> mn(n);
    vector<int> mx(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];        
    }

    mx[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        mx[i] = max(mx[i - 1], v[i]);
    }
    mn[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        mn[i] = min(mn[i + 1], v[i]);
    }
    
    vector<int>ans(n);

    ans[n - 1] = mx[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if(mx[i] > mn[i + 1]){
            ans[i] = ans[i + 1];
        } else{
            ans[i] = mx[i];
        }
    }

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