#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;
    map<int, int> b;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int p = i - x;
        b[p]+=x;
        ans = max(ans, b[p]);
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}