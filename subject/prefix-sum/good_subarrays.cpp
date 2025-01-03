#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    string s;
    cin >> s;

    for(int i = 0; i < n;i++){
        v[i] = (s[i] - '0') - 1;
    }
    
    int ans = 0;
    map<int, int> m;
    m[0] = 1;

    int psum = 0;
    for (int i = 0; i < n; i++)
    {
        psum += v[i];
        ans += m[psum];

        m[psum]++;
    }
    
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}