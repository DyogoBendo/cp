#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    
    int ans = 0;
    for (int i = 0; i < 200; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if(v[j] >= i) cnt++;
        }
        
        if(cnt >= i) ans = i;
    }
    
    cout << ans << endl;
    
}