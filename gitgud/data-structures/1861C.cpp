#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;

    bool possible = true;

    int lst_or = 0;    
    int lst_un = -1;
    int sz = 0;    

    for (auto c : s)
    {        
        if(c == '+'){
            sz ++;            
            if(sz == 1) lst_or = 1;
        } else if(c == '-'){            
            if(sz == lst_un){                
                lst_un = -1;
            }            
            if(lst_or >= 1 && lst_or == sz) lst_or --;
            sz --;
        } else if(c == '1'){
            if(lst_un != -1) possible = false;
            lst_or = sz;
        } else{            
            if(lst_or == sz) possible = false;
            if(lst_un == -1){                                
                lst_un = sz;
            }
        }
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}