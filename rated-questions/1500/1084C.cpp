#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD = 1e9+7;

void solve(){
    string s;
    cin >> s;

    int add = 1;
    int curra= 0;

    int ans = 0;
    for (auto c : s)
    {
        if(c == 'a'){            
            ans = (0LL + ans + add) % MOD;
            curra ++;
        } else if(c == 'b'){
            add =  ( 1LL * (curra + 1) * add) % MOD;
            curra = 0;
        }
    }
    
    cout << ans << endl;
}


signed main(){
     darvem;
    int t = 1;    

    while(t--) solve();
}