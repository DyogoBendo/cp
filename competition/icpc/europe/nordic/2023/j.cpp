#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        q.push(0);
    }
    
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
        
    int ans = v[n-1];

    for (int i = 0; i < n - m; i++)
    {                
        ans = max(ans, v[i] + v[2*(n-m) - i - 1]);
    }
    
    
    cout << ans << endl;   
}