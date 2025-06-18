#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int l, r;
    cin >> l >> r;

    vector<int> d1, d2;

    int curr = 10;
    while(l){        
        d1.push_back(l % 10);
        d2.push_back(r % 10);        
        l/= 10;
        r/= 10;
    }

    int ans = 0;
    while(d1.size() && d1.back() == d2.back()){        
        d1.pop_back();
        d2.pop_back();
        ans += 2;
    }
    
    bool free = false;
    for (int i = d1.size() - 1; i >= 0; i--)
    {        
        if(i == d1.size() - 1){
            if(d2[i] - d1[i] == 1){
                ans ++;
            } else{
                free= true;
            }
        }
        if(i < d1.size() - 1 && !free){
            if(d2[i] == 0 && d1[i] == 9) ans ++;
            else free = true;
        }
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}