#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, j, k;
    cin >> n >> j >> k;

    int ma = 0;

    int pj;
    for (int i = 1; i <= n; i++)
    {        
        if(i == j) cin >> pj;
        else{
            int x;
            cin >> x;
            ma = max(ma, x);
        }
    }    

    if(k > 1){
        cout << "YES" << endl;
    } else{        
        if(pj >= ma) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}