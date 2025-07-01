#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n), p(n+1, 1e7), s(n+1);    

    int lst = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];        
        p[i + 1] = min(p[i], v[i]);

    }    
    
    for (int i = n - 1; i >= 0; i--)
    {
        s[i] = max(s[i + 1], v[i]);
    }
        
    int st = v[0];

    map<int, int> ans;

    for (int i = 0; i < n; i++)
    {
        ans[p[i]] = 1;
        ans[s[i]] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if(ans[v[i]]) cout << 1;
        else cout << 0;
    }
    cout << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}