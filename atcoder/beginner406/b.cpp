#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll n, k;
    cin >> n >> k;
    
    ll mod = 1;
    while(k){
        mod *= 10;
        k--;
    }
    
    ll curr = 1;    
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if(curr > mod / x or (curr == mod/x && mod%x == 0)) curr = 1;        
        else curr *= x;     
    }
    cout << curr << endl;
    
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}