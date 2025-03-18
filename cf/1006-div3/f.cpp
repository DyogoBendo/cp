#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

bool check(int n, int k){
    for (int i = 0; i < 32; i++)
    {
        if(!(n & 1) and (k&1)) return 1;
        n >>= 1;
        k >>= 1;
    }
    return 0;
}

void solve(){
    int n, k;
    cin >> n >> k;

    n--;

    for (int i = 0; i <= n; i++)
    {
        if(!check(n, i)) cout << k;
        else cout << 0;
        cout << " ";
    }
    cout << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}