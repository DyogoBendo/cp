#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll zero = 0;

void solve(){
    ll n, k, x;
    cin >> n >> k;    

    ll s = 0, mx = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s += x;
        mx = max(mx, x);
    }    

    for (int i = n; i >= 1; i--)
    {        
        int mod = s % i;
        ll max_allowed = s / i;       
        
        if(mod == 0 && mx <= max_allowed){
            cout << i << endl;
            return;
        }        

        ll buy_fix_mod = (i - mod) % i;        
        ll buy_fix_max = max(mx * i - s, zero);                    

        if(max(buy_fix_mod,buy_fix_max) <= k){
            cout << i << endl;
            return;
        }
    }
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}