#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (auto & a : v)
    {
        cin >> a;
    }

    int l = 0, r = 0, curr = 0, ans = 0;
    while(r < n){
        curr += v[r];

        while(curr > x){
            curr -= v[l];
            l++;
        }
        if(curr == x) ans ++;
        r++;
    }
    
    cout << ans << endl;
}

signed main(){
    flash;
    solve();
}