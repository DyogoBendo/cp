#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n, w;
    cin >> n >> w;

    vector<int> v(30, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 30; j++)
        {
            v[j] += (x >> j) & 1;
        }        
    }

    int ans = 0, curr = 0;
    
    while(curr != n){
        int x = 0;
        ans ++;
        for (int j = 29; j >= 0; j--)
        {
            while(v[j] && (x + (1 << j)) <= w){
                x += 1 << j;
                v[j]--;
                curr++;
            }
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