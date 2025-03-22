#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans(n+1, 0);

    int bst = 0;
    for (int i = n; i >= 1; i--)
    {
        ans[i] = 1;
        for (int j = 2; j <= n; j++)
        {
            if(i * j > n) break;
            if(v[i] < v[i*j]) ans[i] = max(ans[i], ans[i*j] + 1);            
        }           
        bst = max(bst, ans[i]);
        
    }
    
    cout << bst << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}