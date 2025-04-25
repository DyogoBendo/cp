#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;    
    vector<vector<int>> v(n+1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v[x].push_back(i);
    }

    vector<int> ans(n+1, -1);
    for (int j = 0; j <= n; j++)
    {
        vector<int> a = v[j];
        if(!a.size()) continue;
        int prev = -1;
        int curr = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int dst = a[i] - prev;
            curr = max(dst, curr);
            prev = a[i];

            if(i == a.size() - 1){
                curr = max(curr, n - a[i]);
            }
        }        
        if(ans[curr] == -1) ans[curr] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        if(ans[i-1] == -1) continue;
        if(ans[i] == -1) ans[i] = ans[i-1];
        ans[i] = min(ans[i], ans[i-1]);
    }
    
    
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    
    cout << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}