#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 1;

    int prev = v[0];
    for (int i = 1; i < n; i++)
    {
        if(prev + 1 < v[i]){
            ans ++;
            prev = v[i];
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