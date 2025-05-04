#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD= 1e9+7;

int fast_expo(int a, int b, int M){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (1LL) * a * ans % M;            
        }
        a = (1LL) * a * a % M;
        b>>= 1;
    }

    return ans;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    int k = fast_expo(b, c, MOD-1);    
    cout << fast_expo(a, k, MOD) << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}