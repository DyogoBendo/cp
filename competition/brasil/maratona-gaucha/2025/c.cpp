#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    int lo = 0, hi = 1e9 + 10;

    auto check = [&](int x){        
        
        for(int i = 0; i < n; i++){
            int l = min(v[(i-1 + n) % n], x);
            int r = min(v[(i+1) % n], x);
            int curr = min(v[i], x) - 1;                        

            if(l < curr or r < curr) return false;
        }             
        return true;
    };

    while(lo < hi){
        int m = (hi - lo) / 2 + lo;

        if(check(m)){
            lo = m + 1;
        } else{
            hi = m;
        }
    }
    cout << hi-1 << endl;
}