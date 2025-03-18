#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }    
    
    auto check = [&](int x){        
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++)
        {            
            l -= x;
            r += x;

            l = max(v[i].first, l);
            r = min(v[i].second, r);            

            if(l > r) return false;
        }
        return true;        
    };

    int l = 0, h = 1e9 + 10;
    while(l < h){
        int mid = (h - l) / 2 + l;

        if(check(mid)){
            h = mid;
        } else{
            l = mid + 1;
        }        
    }
    cout << h << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}