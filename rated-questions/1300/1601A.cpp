#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    vector<int> cnt(31, 0);
    
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x) found = true;
        for (int j = 0; j < 31; j++)
        {
            cnt[j] += (x >> j) & 1;
        }        
    }

    if(!found){
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << endl;
        }
        return;        
    }

    int m = -1;
    for (int i = 0; i < 31; i++)
    {
        if(cnt[i] == 0) continue;           

        if(m == -1) m = cnt[i];
        m = __gcd(m, cnt[i]);
    }    
    
    for (int i = 1; i <= m; i++)
    {
        if(m %i ==0) cout << i << ' ';
    }
    
    cout << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}