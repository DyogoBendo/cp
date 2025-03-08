#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<int> cities(n);
    vector<int> towers(m);
    for(int &x: cities) cin >> x;
    for(int &x: towers) cin >> x;
    
    int ans = 0;
    int l = 0;

    for (int c : cities)
    {
        while(l<m && towers[l] < c)l++;
        int curr;
        if(l == 0) curr = towers[l] - c;
        else{
            curr = c - towers[l-1];
            if(l < m) curr = min(curr, towers[l] - c);
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
    
}

signed main(){
    flash;
    int t = 1;    

    while(t--) solve();
}