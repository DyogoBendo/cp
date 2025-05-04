#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD= 1e9+7;

int fast_expo(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (1LL) * a * ans % MOD;            
        }
        a = (1LL) * a * a % MOD;
        b>>= 1;
    }

    return ans;
}

void solve(){
    int a, b;
    cin >> a >> b;

    cout << fast_expo(a, b) << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}