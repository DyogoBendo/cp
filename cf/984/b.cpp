#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(k + 1, 0);

    for (int i = 0; i < k; i++)
    {
        int b, c;
        cin >> b >> c;

        v[b]+= c;
    }

    sort(v.begin(), v.end());

    int i = k;    
    int ans = 0;
    while(n && (i >= 0)){
        n--;
        ans += v[i];
        i--;
    }

    cout << ans << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}