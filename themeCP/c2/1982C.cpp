#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    int x = 0, y = 0, curr = 0, ans = 0;

    while(y <= n){            
        if(curr >= l && curr <= r){            
            ans ++;            
            x = y;
            curr = 0;
        } else if (curr < l){
            if(y < n) curr += v[y];
            y++;
        } else{
            curr -= v[x];
            x++;
        }
    }       

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}