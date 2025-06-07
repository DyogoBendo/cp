#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int M = 1e9+7;

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;
    int curr = 1, ans = 0;

    while(m){
        if(m%2){
            ans += curr;
            ans %= M;
        }
        m/=2;
        curr = (curr *n) % M;
    }

    cout << ans << endl;
}