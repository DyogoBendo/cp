#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, q, curr = 0, x;    
    string ans = "";    
    cin >> n;    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {    
            cin >> x;   
            curr ^= (i == j & x);
        }
        
    }
    cin >> q;
    while(q--){
        int o;
        cin >> o;
        if(o < 3){  
            cin >> x;
            curr ^= 1;
        } else{            
            char c = curr + '0';            
            cout << c;
        }
    }    
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;

    while(t--) solve();
}