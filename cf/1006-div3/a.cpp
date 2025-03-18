#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k, p;
    cin >> n >> k >> p;

    k = max(k, -k);

    int ans = -1;
    int curr = 0;
    if(k == 0){
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        curr += p;
        if(curr >= k){
            ans = i + 1;
            break;
        }
    }
    
    cout << (ans) << endl;

}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}