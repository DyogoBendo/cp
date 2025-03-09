#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;
    
    vector<pair<int, int>> v(n);    
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;        

        int bigger = 0;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            x -= j;
            bigger = max(bigger, x);
        }        
        v[i] = {bigger, k};        
    }

    sort(v.begin(), v.end());

    int ans = 0, str = 0;
    for (int i = 0; i < n; i++)
    {        
        if(v[i].first >= str){
            ans += v[i].first - str + 1;
            str = v[i].first + 1;
        }
        str += v[i].second;        
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}