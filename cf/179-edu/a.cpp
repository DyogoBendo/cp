#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int x;
    cin >> x;

    vector<int> v(3);

    bool ended = false;
    int ans = 0;

    while(!ended){
        for (int i = 0; i < 3; i++)
        {
            if(v[i] == x) continue;
            int mx = x;
            for (int j = 0; j < 3; j++)
            {
                if(i == j) continue;
                mx = min((v[j] * 2 + 1), mx);
            }
            
            v[i] = mx;
            ans ++;
        }
        bool found = false;
        for (int i = 0; i < 3; i++)
        {
            if(v[i] != x) found = true;
        }
        
        if(!found) break;
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}