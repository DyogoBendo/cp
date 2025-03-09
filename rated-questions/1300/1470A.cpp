#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long


void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> positions(n);
    vector<int> gifts(m);
    for (int i = 0; i < n; i++)
    {
        cin >> positions[i];        
    }

    for (int i = 0; i < m; i++)
    {
        cin >> gifts[i];
    }
    

    sort(positions.rbegin(), positions.rend());
    

    int l = 0;
    int ans=  0;
    for (int i = 0; i < n; i++)
    {
        int k = positions[i] - 1;        
        if(l < m && gifts[k] > gifts[l]){
            ans += gifts[l];
            l ++;
        } else{
            ans += gifts[k];
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