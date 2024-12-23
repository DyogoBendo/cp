#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> psum(n + 1, 0);
    vector<int> mx(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        psum[i + 1] = psum[i] + x;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mx[i + 1] = max(mx[i], x);
    }
    
    int ans = 0;
    for (int i = 1; i <= min(n, k); i++)
    {
        ans = max(ans, psum[i] + (k - i) * mx[i]);
    }
    
    cout << ans << endl;    
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}