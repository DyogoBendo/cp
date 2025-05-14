#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;    

    auto check = [&](int l, int r){
        cout << "? " << l << " " << r << endl;
        cout.flush();        
        int cnt = 0;
        for (int i = l; i <= r; i++)
        {
            int x;
            cin >> x;
            if(x >= l && x <= r) cnt^=1;
        }
        
        return cnt;        
    };
    
    int l = 1, r = n+1;
    while(l < r){
        int m = (r - l) / 2 + l;

        if(check(l, m)){
            r = m;
        } else{
            l = m+1;
        }
    }
    cout << "! " << r << endl;
    cout.flush();
}


signed main(){    
    int t = 1;
    cin >> t;

    while(t--) solve();
}