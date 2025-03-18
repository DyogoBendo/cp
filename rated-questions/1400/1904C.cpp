#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    if(k > 2){
        cout << 0 << endl;
        return;
    }

    sort(v.begin(), v.end());
    int ans = 1e18;

    for (int i = 0; i < n - 1; i++)
    {        
        ans = min({v[i], v[i + 1], v[i + 1] - v[i], ans});
    }    

    if(k == 2){
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = v[j] - v[i];

                int pos = lower_bound(v.begin(), v.end(), diff) - v.begin();                            

                if(pos > 0){
                    ans = min(ans, diff - v[pos - 1]);
                }
                if(pos < n - 1){
                    ans = min(ans, v[pos] - diff);
                }
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